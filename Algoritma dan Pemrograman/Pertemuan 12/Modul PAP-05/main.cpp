#include <iostream>
#include "pustaka.h"

using namespace std;

int main()
{
    //Soal nomor 1
    cout << "Soal nomor 1:" << endl;
    int arr1[] = { 3, 5, 38, 0, 44, 47 };
    compress_array(arr1, 6);
    int arr2[] = { 3, 0, 44, 38, 0, 5, 47 };
    compress_array(arr2, 7);
    int arr3[] = { 2, 15, 0, 0, 0, 26, 27, 36 };
    compress_array(arr3, 8);
    int arr4[] = { 15, 36, 27, 0, 0, 2, 26 };
    compress_array(arr4, 7);
    cout<< endl;

    //Soal nomor 2
    cout << "Soal nomor 2:" << endl;
    int arr5[] = { 3, 44, 38, 5, 47 };
    selection_sort(arr5, 5);
    cout << endl;
    int arr6[] = { 15, 36, 27, 2, 26 };
    selection_sort(arr6, 5);
    cout << endl;

    //Soal nomor 3
    cout << "Soal nomor 3:" << endl;
    int arr7[] = { 3, 44, 38, 5, 47 };
    int arr8[] = { 15, 36, 27, 2, 26 };
    selection_sort2(arr7, 5);
    cout << endl;
    selection_sort2(arr8, 5);
    cout << endl;

    //Soal nomor 4
    cout << "Soal nomor 4:" << endl;
    int arr9[] = { 3, 44, 38, 5, 47 };
    get_median(arr9, 5);
    cout << "" ;
    int arr10[] = { 15, 36, 27, 2, 26 };
    get_median(arr10, 5);
    cout << endl;
    return 0;
}

