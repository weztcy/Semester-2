#include <iostream>
#include "header.h"

using namespace std;
void insertionSort(int arr[], int n);
int main()
{
    int arrI[]={7, 30, 3, 22};
    int sI = sizeof(arrI)/sizeof(arrI[0]);

    cout << "Step 1, sebelum array proses Insertion-Sort: \n";
    printArray(arrI, sI);
    insertionSort(arrI, sI);
    cout << "Step 2, sesudah array proses Insertion-Sort: \n";
    printArray(arrI, sI);
    return 0;
}


