#include "pustaka.h"
#include <iostream>

using namespace std;

bool is_sort(int arr[], int length) {
    bool is_sort = true;
    int tempVal = 0;

    for(int i = 0; i < (length+1); i++){
        if(tempVal > arr[i]){
            is_sort = false;
        }
        tempVal = arr[i];
    }

    return is_sort;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int show = 0;
    for(i=0; i<n-1; i++){
        for(j=0; j<(n-i-1); j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        int if_sort = is_sort(arr, (n-1));

        if(show == 0){
            for(int j=0; j<n; j++){
                cout << arr[j] << " ";
            }
            cout << endl;

            if(if_sort == 1){
                show = 1;
            }
        }
    }
}
