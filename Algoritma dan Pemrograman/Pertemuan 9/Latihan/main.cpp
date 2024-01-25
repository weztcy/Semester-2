#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int a, b;
    a=3, b=10;
    cout << "Sebelum swab\na = "<<a<<"\tb = "<<b<<endl;
    swapAngka(a, b);
    cout << "Sesudah swab\na = "<<a<<"\tb = "<<b<<endl;

    int arrB[] = {7, 57, 49, 3};
    int sB = sizeof(arrB)/sizeof(arrB[0]);//size of array otomatis
    cout << sizeof(arrB) << "/" << sizeof(arrB[0]) << endl;
    //sizeof u/ menghasilkan ukuran dalam byte
    //sizeof (arrB) -> 16, karena ada 4 int, tiap int sizenya 4
    //sizeof(arrB[0]) -> 4, tiap int sizenya 4
    //sB = 16/4 = 4

    cout << "Sebelum array di sorting\n";
    printArray(arrB, sB);
    bublesort(arrB, sB);
    cout << "Setelah array di sorting\n";
    printArray(arrB, sB);

    int arrS[]={7, 30, 3, 22};
    int sS = sizeof(arrS)/sizeof(arrS[0]);

    cout << "Sebelmun arrayS proses SelectionSort\n";
    printArray(arrS, sS);
    selectionSort(arrS, sS);
    cout << "Sesudah arrayS proses SelectionSort\n";
    printArray(arrS, sS);

    return 0;
}
