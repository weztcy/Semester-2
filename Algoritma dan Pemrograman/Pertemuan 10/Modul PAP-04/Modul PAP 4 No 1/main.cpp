#include <iostream>
#include "pustaka.h"

using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 0, 0, 0, 0};
    int arr2[] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0};
    int arr3[] = {2, 4, 9, 5, 1, 0, 0, 0, 0, 0};
    int arr4[] = {2, 8, 5, 0, 0, 0, 0, 0, 0, 0};

    countArray(arr1, 10);
    countArray(arr2, 10);
    countArray(arr3, 10);
    countArray(arr4, 10);

    return 0;
}
