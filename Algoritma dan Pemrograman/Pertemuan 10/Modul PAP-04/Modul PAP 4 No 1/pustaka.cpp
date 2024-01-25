#include "pustaka.h"
#include <iostream>

using namespace std;

void countArray(int n[], int size) {
    int i, j, k = 0;
    for (i = 1; i < size; i++){
        for (j = 0; j < i; j++){
            if (n[i] == n[j]){
                break;
            }
        }
        if (i == j){
            k++;
        }
    }
    cout << k << endl;
}
