#include "Declarations.h"
//#include <windows.h>
//#include <conio.h>
//#include "keys.h"
#include "math.h"
#include <stdbool.h>

void InitProgram(int argc, char *argv[]);


extern void DrawRow(int row, int col, int len, unsigned char color, char *text);
extern void ColorRow(int row, int col, int len, unsigned char color);

int MenuTopRow = 10; // topmost menu row on the screen
int MenuLeftColumn = 10; // leftmost menu column on the screen
int MenuWidth = 7; // menu width in columns

extern HANDLE gDoneEvent;
int SetTimerFun();
void DeleteTimer();

double deg2rad(double degrees) {
	return (degrees * 4.0 * atan(1.0)) / 180.0;
}


int main(int argc, char *argv[])
{
	int row_0 = 5, col =10;
	int col_0, col_1, col_2;
	printf("Please input direction (angle in degrees): ");
	double direction;
	scanf("%lf", &direction);
	printf("Please input animation speed: ");
	/*
	int wholePart = (int) direction / 360;
	direction = (direction / 360 - wholePart) * direction;
	*/
	double speed;
	scanf("%lf", &speed);
	double incr_col_0 = cos(deg2rad(direction)) * speed;
	double incr_col_1 = cos(deg2rad(direction)) * speed;
	double incr_col_2 = cos(deg2rad(direction)) * speed;
	double incr_row_0 = sin(deg2rad(direction)) * speed;
	double incr_row_1 = sin(deg2rad(direction)) * speed;
	double incr_row_2 = sin(deg2rad(direction)) * speed;
	int row_1 = incr_row_0 + speed + 2;
	int row_2 = incr_row_0 + speed + 2;
	int i;
	int KEY=0;

	char string[] = "Demo stirng";
	char *temp;
	unsigned char colour;

	InitProgram(argc, argv);
	set_window_title(Caption);

	/*

		// single chcaracter on row 5 , col 10
	mainchInfo[row_0 * coord.X + col].Char.AsciiChar = '*';
	mainchInfo[row_0 * coord.X + col].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

	put_screen(&coord, mainchInfo);

	for ( row_0 = 5; row_0 < 20 ; row_0++){
		for( col = 10; col < 30 ; col++){
			mainchInfo[row_0 * coord.X + col].Char.AsciiChar = ' ';
			mainchInfo[row_0 * coord.X + col].Attributes = 0x60;
		}
		put_screen(&coord, mainchInfo);
	}

	*/

	row_0 = incr_row_0 + speed + 2;
	col_0 = incr_col_0 + speed + 4;
	col_1 = incr_col_0 + speed + 3;
	col_2 = incr_col_0 + speed + 2;

	mainchInfo[row_0 * coord.X + col_0].Char.AsciiChar = '*';
	mainchInfo[row_0 * coord.X + col_0].Attributes = 0x09;
	mainchInfo[row_0 * coord.X + col_1].Char.AsciiChar = '*';
	mainchInfo[row_0 * coord.X + col_1].Attributes = 0x0A;
	mainchInfo[row_0 * coord.X + col_2].Char.AsciiChar = '*';
	mainchInfo[row_0 * coord.X + col_2].Attributes = 0x0C;
	boolean starsInFront;
	if (direction / 180 > 1)
	{
		starsInFront = true;
	}
	else {
		starsInFront = false;
	}
	put_screen(&coord, mainchInfo);
		SetTimerFun();

	  // Wait for the timer-queue thread to complete using an event 
    // object. The thread will signal the event at that time.
/**/
	do{
		if (WaitForSingleObject(gDoneEvent, INFINITE) != WAIT_OBJECT_0) {
			printf("WaitForSingleObject failed (%d)\n", GetLastError());
			break;
		}
		ResetEvent(gDoneEvent);
		
		mainchInfo[row_0 * coord.X + col_0].Char.AsciiChar = 0x20;
		mainchInfo[row_0 * coord.X + col_0].Attributes = 0x00;
		mainchInfo[row_1 * coord.X + col_1].Char.AsciiChar = 0x20;
		mainchInfo[row_1 * coord.X + col_1].Attributes = 0x00;
		mainchInfo[row_2 * coord.X + col_2].Char.AsciiChar = 0x20;
		mainchInfo[row_2 * coord.X + col_2].Attributes = 0x00;
		if (col_0 >= coord.X - speed) {
			direction = -direction;
			incr_col_0 = 0 - incr_col_0;
			starsInFront = true;
		}
		else if (col_0 <= 0 + speed) {
			direction = 180 - direction;
			incr_col_0 = 0 - incr_col_0;
			starsInFront = false;
		}
		col_0 += round(incr_col_0);
		if (starsInFront)
		{
			col_1 = col_0 + 1;
			col_2 = col_0 + 2;
		}
		else {
			col_1 = col_0 - 1;
			col_2 = col_0 - 2;
		}

		/*
		if (col_1 >= coord.X - speed) {
			direction = -direction;
			incr_col_1 = 0 - incr_col_1;
		}
		else if (col_1 <= 0 + speed) {
			direction = 180 - direction;
			incr_col_1 = 0 - incr_col_1;
		}
		col_1 += round(incr_col_1);

		if (col_2 >= coord.X - speed) {
			direction = -direction;
			incr_col_2 = 0 - incr_col_2;
		}
		else if (col_2 <= 0 + speed) {
			direction = 180 - direction;
			incr_col_2 = 0 - incr_col_2;
		}
		col_2 += round(incr_col_2);
		*/

		if (row_0 >= coord.Y - speed) {
			direction = 180 - direction;
			incr_row_0 = 0 - incr_row_0;
		}
		else if (row_0 <= 0 + speed) {
			direction = -direction;
			incr_row_0 = 0 - incr_row_0;
		}
		row_0 += round(incr_row_0);
		row_1 = row_0;
		row_2 = row_0;

		/*
		if (row_1 >= coord.Y - speed) {
			direction = 180 - direction;
			incr_row_1 = 0 - incr_row_1;
			
		}
		else if (row_1 <= 0 + speed) {
			direction = -direction;
			incr_row_1 = 0 - incr_row_1;
		}
		row_1 += round(incr_row_1);

		if (row_2 >= coord.Y - speed) {
			direction = 180 - direction;
			incr_row_2 = 0 - incr_row_2;
		}
		else if (row_2 <= 0 + speed) {
			direction = -direction;
			incr_row_2 = 0 - incr_row_2;
		}
		row_2 += round(incr_row_2);
		*/

		mainchInfo[row_0 * coord.X + col_0].Char.AsciiChar = '#';
		mainchInfo[row_0 * coord.X + col_0].Attributes = 0x70;
		mainchInfo[row_1 * coord.X + col_1].Char.AsciiChar = '*';
		mainchInfo[row_1 * coord.X + col_1].Attributes = 0x0A;
		mainchInfo[row_2 * coord.X + col_2].Char.AsciiChar = '*';
		mainchInfo[row_2 * coord.X + col_2].Attributes = 0x0C;
		put_screen(&coord, mainchInfo);
		if (_kbhit()){			KEY = GetKey();		}

	} while ( KEY != KEY_UP );

 	DeleteTimer();

	return 1;
}

int GetKey()
{
	int ch;
	ch = _getch();
	if (ch == 0 || ch == 224){
		ch = _getch();
		ch += 256;
	}
	return ch;
}

void InitProgram(int argc, char *argv[])
{
	int i;
	char CAPTION[] = "Console application WINDOWS timers";

	for(i=0; CAPTION[i] != 0; i++)
		Caption[i] = (unsigned short) CAPTION[i];

	mainchInfo = get_screen(&coord);

	init_console(KBValue);
}

void ColorRow(int row, int col, int len, unsigned char color)
{
	int pos;

	for( pos = 0 ; len != 0 ; pos++, len--){
		mainchInfo[row * coord.X + col+pos].Attributes = color;
	}
}

void DrawRow(int row, int col, int len, unsigned char color, char *text)
{
	int pos;

	for( pos = 0 ; len != 0 ; pos++, text++, len--){
		mainchInfo[row * coord.X + col+pos].Char.AsciiChar = *text;
		mainchInfo[row * coord.X + col+pos].Attributes = color;
	}
}



