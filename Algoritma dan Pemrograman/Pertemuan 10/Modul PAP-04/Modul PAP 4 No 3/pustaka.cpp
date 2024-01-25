#include "pustaka.h"
#include <iostream>

using namespace std;

void bubbleSort(int n[], int size) {
    int i, j, temp;
    for(int y; y<size; y++){
        cout << n[y] << " ";
    }
    cout << endl;
    for (i = 0; i < size - 1; i++){
        for (j = 0; j < size - i - 1; j++){
            if (n[j] > n[j + 1]){
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
        for(int y=0; y < size; y++) {
            cout << n[y] << " ";
        }
        cout << endl;
    }
}
