#include "Sort.h"
#include <iostream>

template<class T> void Sort::mergeSort(vector<T> &vet)
{
    Sort::mergeSortRec(vet);
}


template<class T> void Sort::mergeSortRec(vector<T> &vet)
{
    if (vet.size() > 1)
    {
        typename vector<T>::iterator meio = vet.begin() + (vet.size() / 2);

        vector<T> left(vet.begin(), meio);
        vector<T> right(meio, vet.end());

        Sort::mergeSortRec(left);
        Sort::mergeSortRec(right);

        unsigned int itLeft = 0, itRight = 0, itVet = 0;

        while (itLeft < left.size() && itRight < right.size())
        {
            if (left[itLeft] < right[itRight])
                vet[itVet++] = left[itLeft++];

            else
                vet[itVet++] = right[itRight++];
        }

        while (itLeft < left.size())
            vet[itVet++] = left[itLeft++];

        while (itRight < right.size())
            vet[itVet++] = right[itRight++];
    }
}

template<class T> void Sort::insertionSort(vector<T> &vet)
{
    for (unsigned int i = 1; i < vet.size(); i++)
    {
        T pivo = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > pivo)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = pivo;
    }
}
