#include "Rod.h"

void Rod::cuttingRod(vector<int> price)
{
    int val[price.size() + 1];
    val[0] = 0;
    int i, j;

    int max_val;
    for (i = 1; i<= price.size(); i++)
    {
        max_val = 0;

        for (j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i-j-1]);
        val[i] = max_val;
    }
}

int Rod::max(int a, int b)
{
    return a > b ? a : b;
}