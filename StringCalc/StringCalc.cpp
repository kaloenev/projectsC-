// StringCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string addition(string firstNumber, string secondNumber);
string subtraction(string firstNumber, string secondNumber);
string multiplication(string firstNumber, string secondNumber, bool isNegative, bool removedMinus);
string longDivision(string number, string divisor, bool isNegative, bool removedMinus);
string removeMinuses(string result);

int main() {
	string firstNumber;
	std::cin >> firstNumber;
	string secondNumber;
	std::cin >> secondNumber;
	string result;
	std::cin >> result;
	if (result == "+")
	{
		result = addition(firstNumber, secondNumber);
	}
	else if (result == "-")
	{
		result = subtraction(firstNumber, secondNumber);
	}
	else if (result == "*")
	{
		result = multiplication(firstNumber, secondNumber, false, false);
	}
	else if (result == "/")
	{
		result = longDivision(firstNumber, secondNumber, false, false);
	}
	else {
		result = "Wrong input";
	}
	std::cout << result;
	return 0;
}

string addition(string firstNumber, string secondNumber) {
	if (firstNumber[0] == '(') {
		if (firstNumber[firstNumber.size() - 1] != ')')
		{
			return "Bracket must be closed";
		}
		firstNumber = firstNumber.substr(1, firstNumber.size() - 2);
		return addition(firstNumber, secondNumber);
	}
	if (secondNumber[0] == '(') {
		if (secondNumber[secondNumber.size() - 1] != ')')
		{
			return "Bracket must be closed";
		}
		secondNumber = secondNumber.substr(1, secondNumber.size() - 2);
		return addition(firstNumber, secondNumber);
	}
	if (firstNumber[0] == '-') {
		firstNumber = firstNumber.substr(1);
		return subtraction(secondNumber, firstNumber);
	}
	if (secondNumber[0] == '-') {
		secondNumber = secondNumber.substr(1);
		return subtraction(firstNumber, secondNumber);
	}
	int numberLengthDiff = firstNumber.length() - secondNumber.length();
	if (numberLengthDiff < 0) {
		for (int j = numberLengthDiff; j < 0; j++) {
			firstNumber = "0" + firstNumber;
		}
	}
	else if (numberLengthDiff > 0) {
		for (int j = numberLengthDiff; j > 0; j--) {
			secondNumber = "0" + secondNumber;
		}
	}
	string result = "";
	bool carryOutOne = false;
	for (int i = firstNumber.length() - 1; i >= 0; i--) {
		string currentResult;
		char firstChar = firstNumber[i];
		char secondChar = secondNumber[i];
		if (!isdigit(firstChar) || !isdigit(secondChar))
		{
			return "Error, number contains non digit characters";
		}
		if (carryOutOne) {
			currentResult = to_string(atoi(&firstChar) + atoi(&secondChar) + 1);
		}
		else {
			currentResult = to_string(atoi(&firstChar) + atoi(&secondChar));
		}
		if (currentResult.length() == 2) {
			result = currentResult[1] + result;
			carryOutOne = true;
		}
		else {
			result = currentResult + result;
			carryOutOne = false;
		}
	}
	if (carryOutOne) result = "1" + result;
	while (result[0] == '0' && result.size() != 1) {
		result = result.substr(1);
	}
	return removeMinuses(result);
}




	string subtraction(string firstNumber, string secondNumber) {
		if (firstNumber[0] == '(') {
			if (firstNumber[firstNumber.size() - 1] != ')')
			{
				return "Bracket must be closed";
			}
			firstNumber = firstNumber.substr(1, firstNumber.size() - 2);
			return subtraction(firstNumber, secondNumber);
		}
		if (secondNumber[0] == '(') {
			if (secondNumber[secondNumber.size() - 1] != ')')
			{
				return "Bracket must be closed";
			}
			secondNumber = secondNumber.substr(1, secondNumber.size() - 2);
			return subtraction(firstNumber, secondNumber);
		}
		if (firstNumber[0] == '-') {
			firstNumber = firstNumber.substr(1);
			return removeMinuses("-" + addition(secondNumber, firstNumber));
		}
		if (secondNumber[0] == '-') {
			secondNumber = secondNumber.substr(1);
			return addition(secondNumber, firstNumber);
		}
		int numberLengthDiff = firstNumber.length() - secondNumber.length();
		if (numberLengthDiff < 0) {
			for (int j = numberLengthDiff; j < 0; j++) {
				firstNumber = "0" + firstNumber;
			}
		}
		else if (numberLengthDiff > 0) {
			for (int j = numberLengthDiff; j > 0; j--) {
				secondNumber = "0" + secondNumber;
			}
		}
		for (int j = 0; j < secondNumber.size(); j++)
		{
			char firstChar = firstNumber[j];
			char secondChar = secondNumber[j];
			if (atoi(&firstChar) < atoi(&secondChar))
			{
				return "-" + subtraction(secondNumber, firstNumber);
			}
			else if (atoi(&firstChar) > atoi(&secondChar)) {
				break;
			}
		}
		string result = "";
		bool carryOutOne = false;
		for (int i = firstNumber.length() - 1; i >= 0; i--) {
			string currentResult;
			char firstChar = firstNumber[i];
			char secondChar = secondNumber[i];
			if (!isdigit(firstChar) || !isdigit(secondChar))
			{
				return "Error, number contains non digit characters";
			}
			if (carryOutOne) {
				currentResult = to_string(atoi(&firstChar) - atoi(&secondChar) - 1);
			}
			else {
				currentResult = to_string(atoi(&firstChar) - atoi(&secondChar));
			}
			if (currentResult.length() == 2) {
				if (i == 0)
				{
					result = currentResult[1] + result;
				}
				else {
					result = to_string(stoi(currentResult) + 10) + result;
				}
				carryOutOne = true;
			}
			else {
				result = currentResult + result;
				carryOutOne = false;
			}
		}
		while (result[0] == '0' && result.size() != 1) {
			result = result.substr(1);
		}
		if (carryOutOne) result = "-" + result;
		return removeMinuses(result);
	}


	string multiplication(string firstNumber, string secondNumber, bool isNegative, bool removedMinus) {
		if (firstNumber[0] == '(') {
			if (firstNumber[firstNumber.size() - 1] != ')')
			{
				return "Bracket must be closed";
			}
			firstNumber = firstNumber.substr(1, firstNumber.size() - 2);
			return multiplication(firstNumber, secondNumber, isNegative, removedMinus);
		}
		if (secondNumber[0] == '(') {
			if (secondNumber[secondNumber.size() - 1] != ')')
			{
				return "Bracket must be closed";
			}
			secondNumber = secondNumber.substr(1, secondNumber.size() - 2);
			return multiplication(firstNumber, secondNumber, isNegative, removedMinus);
		}
		if (firstNumber[0] == '-') {
			if (secondNumber[0] != '-') {
				isNegative = true;
			}
			firstNumber = firstNumber.substr(1);
			removedMinus = true;
			return multiplication(firstNumber, secondNumber, isNegative, removedMinus);
		}
		if (secondNumber[0] == '-') {
			if (!removedMinus) {
				isNegative = true;
			}
			secondNumber = secondNumber.substr(1);
			return multiplication(firstNumber, secondNumber, isNegative, removedMinus);
		}
		string overallResult = "";
		int carryOutNumber = 0;
		for (int j = secondNumber.length() - 1; j >= 0; j--) {
			char secondChar = secondNumber[j];
			string result = "";
			for (int i = firstNumber.length() - 1; i >= 0; i--) {
				string currentResult;
				char firstChar = firstNumber[i];
				if (!isdigit(firstChar) || !isdigit(secondChar))
				{
					return "Error, number contains non digit characters";
				}
				currentResult = to_string(atoi(&firstChar) * atoi(&secondChar) + carryOutNumber);
				if (currentResult.length() == 2) {
					result = currentResult[1] + result;
					char carryOut = currentResult[0];
					carryOutNumber = atoi(&carryOut);
				}
				else {
					result = currentResult + result;
					carryOutNumber = 0;
				}
			}
			if (carryOutNumber != 0) result = to_string(carryOutNumber) + result;
			carryOutNumber = 0;
			for (int zerosCount = secondNumber.length() - j - 1; zerosCount > 0; zerosCount--) {
				result = result + "0";
			}
			if (!overallResult.empty()) overallResult = addition(overallResult, result);
			else overallResult = result;
		}
		
		while (overallResult[0] == '0' && overallResult.size() != 1) {
			overallResult = overallResult.substr(1);
		}
		if (isNegative) overallResult = "-" + overallResult;
		return overallResult;
	}

	string longDivision(string firstNumber, string secondNumber, bool isNegative, bool removedMinus)
	{
		if (firstNumber[0] == '(') {
			if (firstNumber[firstNumber.size() - 1] != ')')
			{
				return "Bracket must be closed";
			}
			firstNumber = firstNumber.substr(1, firstNumber.size() - 2);
			return longDivision(firstNumber, secondNumber, isNegative, removedMinus);
		}
		if (secondNumber[0] == '(') {
			if (secondNumber[secondNumber.size() - 1] != ')')
			{
				return "Bracket must be closed";
			}
			secondNumber = secondNumber.substr(1, secondNumber.size() - 2);
			return longDivision(firstNumber, secondNumber, isNegative, removedMinus);
		}
		if (firstNumber[0] == '-') {
			if (secondNumber[0] != '-') {
				isNegative = true;
			}
			firstNumber = firstNumber.substr(1);
			removedMinus = true;
			return longDivision(firstNumber, secondNumber, isNegative, removedMinus);
		}
		if (secondNumber[0] == '-') {
			if (!removedMinus) {
				isNegative = true;
			}
			secondNumber = secondNumber.substr(1);
			return longDivision(firstNumber, secondNumber, isNegative, removedMinus);
		}
		while (firstNumber[0] == '0' && firstNumber.size() != 1) {
			firstNumber = firstNumber.substr(1);
		}
		while (secondNumber[0] == '0' && secondNumber.size() != 1) {
			secondNumber = secondNumber.substr(1);
		}
		if (secondNumber[0] == '0')
		{
			return "Error, can not divide by 0";
		}
		for (int i = 0; i < firstNumber.length(); i++)
		{
			if (!isdigit(firstNumber[i]))
			{
				return "Error, number contains non digit characters";
			}
		}
		for (int i = 0; i < secondNumber.length(); i++)
		{
			if (!isdigit(secondNumber[i]))
			{
				return "Error, number contains non digit characters";
			}
		}
		string result;
		int divisor = stoi(secondNumber);

		int idx = 0;
		int temp = firstNumber[idx] - '0';
		while (temp < divisor)
			temp = temp * 10 + (firstNumber[++idx] - '0');

		while (firstNumber.size() > idx) {

			result += (temp / divisor) + '0';

			temp = (temp % divisor) * 10 + firstNumber[++idx] - '0';
		}

		if (result.length() == 0)
			return "0";

		while (result[0] == '0' && result.size() != 1) {
			result = result.substr(1);
		}
		if (isNegative) result = "-" + result;
		return result;
	}

	string removeMinuses(string result) {
		while (result[0] == '-' && result[1] == '-') {
			result = result.substr(2);
		}
		return result;
	}