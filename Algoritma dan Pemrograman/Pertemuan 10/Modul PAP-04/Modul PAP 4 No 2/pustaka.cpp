#include "pustaka.h"
#include <iostream>

using namespace std;

void arraySort(int n[], int size) {
    for (int i=0; i < size-1; i++) {
        if (n[i] > n[i+1]) {
            cout << "false" << endl;
            return;
        }
    }

    cout << "true" << endl;
}
