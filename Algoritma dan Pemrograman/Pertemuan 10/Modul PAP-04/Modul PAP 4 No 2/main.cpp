#include <iostream>
#include "pustaka.h"

using namespace std;

int main()
{
    int arr1[] = { 3, 5, 38, 44, 47 };
    int arr2[] = { 3, 44, 38, 5, 47 };
    int arr3[] = { 2, 15, 26, 27, 36 };
    int arr4[] = { 15, 36, 27, 2, 26 };

    arraySort(arr1, 5);
    arraySort(arr2, 5);
    arraySort(arr3, 5);
    arraySort(arr4, 5);

    return 0;
}
