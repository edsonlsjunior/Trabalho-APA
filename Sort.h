#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

class Sort {
public:
	template<class T> static void mergeSort(vector<T> &vet);
    template <class T> static void insertionSort(vector<T> &vet);

private:
	template<class T> static void mergeSortRec(vector<T> &vet);

};

#endif
