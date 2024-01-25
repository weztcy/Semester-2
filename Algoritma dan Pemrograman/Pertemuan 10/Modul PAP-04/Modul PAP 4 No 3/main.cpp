#include "pustaka.h"
#include <iostream>

using namespace std;

int main()
{
    int arr1[] = { 3, 44, 38, 5, 47 };
    int arr2[] = { 15, 36, 27, 2, 26 };

    bubbleSort(arr1, 5);
    cout << endl;
    bubbleSort(arr2, 5);
    cout << endl;
    return 0;
}
