#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

void swapAngka(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
// untuk mengambil alamat memori
void bublesort (int arr[], int n)
{
    int i, j;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapAngka(arr[j], arr[j+1]);
            }
        }
    }
}
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    //Cara lainnya
    //int i, j, min_idx, temp;
    for(i=0; i<n-1; i++)
    {
        min_idx = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swapAngka(arr[min_idx], arr[i]);
        /*Cara lain
        temp=arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        jika menukar dalam 1 fungsi/prosedur, tidak pakai &*/
    }
}
#endif // HEADER_H_INCLUDED
