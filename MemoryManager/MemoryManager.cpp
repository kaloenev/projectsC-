#include <iostream>

class myVector {
    double** pages;
    int currentPage;
    int currentIndex;
    int pageSize;
    int numberOfPages;

public:
    myVector(int pageSizeGiven) {
        double **pages1 = new double*[1];
        pages = pages1;
        pages[0] = new double[pageSizeGiven];
        currentPage = 0;
        currentIndex = -1;
        pageSize = pageSizeGiven;
        numberOfPages = 1;
    }

    void push(double data) {
        currentIndex++;
        if (currentIndex >= pageSize)
        {
            if (currentPage >= numberOfPages - 1)
            {
                doubleArraySize();
            }
            currentPage++;
            currentIndex = 0;
            pages[currentPage] = new double[pageSize];
        }
        pages[currentPage][currentIndex] = data;
    }

    double get(int page, int index) {
        if (page < 0 || page > currentPage || index > pageSize - 1 || index < 0)
        {
            return INT_MIN;
        }
        return pages[page][index];
    }

    double get(int index) {
        if (index > currentIndex || index < 0)
        {
            return INT_MIN;
        }
        return pages[currentPage][index];
    }

    double getLast() {
        return pages[currentPage][currentIndex];
    }

    double pop() {
        if (currentPage <= 0 && currentIndex < 0)
        {
            return INT_MIN;
        }
        double data = pages[currentPage][currentIndex];
        pages[currentPage][currentIndex] = 0.0;
        currentIndex--;
        if (currentIndex < 0)
        {
            currentPage--;
            currentIndex = pageSize - 1;
        }
        return data;
    }

    int size() {
        return currentPage * pageSize + currentIndex + 1;
    }

    private:
        void doubleArraySize() {
            numberOfPages *= 2;
            double** pages1 = new double* [numberOfPages];
            for (int i = 0; i < numberOfPages / 2; i++)
            {
                pages1[i] = pages[i];
            }
            pages = pages1;
        }
};
int main()
{
    myVector vector(10);
    try {
        while (true) {
            vector.push(12);
        }
    }
    catch (std::bad_alloc) {
        std::cout << vector.size();
        return 0;
    }
    return 0;
}
