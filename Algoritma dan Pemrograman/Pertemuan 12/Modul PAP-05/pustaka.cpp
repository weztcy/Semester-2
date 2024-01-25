#include <iostream>
#include "pustaka.h"

using namespace std;

//Soal nomor 1
void compress_array(int n[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(n[i] == 0)
        {
            n[i]= NULL;
        }
        else
        {
            cout << n[i] <<" ";
        }
    }
    cout<< endl;
}

//Soal nomor 2
void selection_sort(int n[], int size)
{
    int i, j ,k , min;
    for(i = 0; i < size; i++)
    {
        min = i;
        for(j = i+1; j < size; j++)
        {
            if(n[j] < n[min])
            {
                min = j;
            }
        }

        k = n[i];
        n[i] = n[min];
        n[min] = k;

        for(int y=0; y<size; y++)
        {
            cout<< n[y] << " ";
        }
        cout<< endl;
    }
}

//Soal nomor 3
bool is_it_sorted(int data[], int jml_data) {
    bool isSorted = true;
    int temp = 0;

    for (int i=0; i<jml_data+1; i++) {
        if(temp>data[i]) {
            isSorted = false;
        }
        temp=data[i];
    }

    return isSorted;
}

void selection_sort2(int data[], int jml_data) {
    int i, j, x, y, min, temp;
    x=0;
    bool sorted = true;

    for (i = 0; i < jml_data - 1; i++) {
        min = i;
        for (j = i + 1; j < jml_data; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }

        temp = data[i];
        data[i] = data[min];
        data[min] = temp;

        sorted = is_it_sorted(data, jml_data-1);

        if(x==0) {
            for(int i=0;i<jml_data;i++) {
                cout << data[i] << " ";
            }
            cout << endl;

            if(sorted == true) {
                x=1;
            }
        }
    }
}

//Soal nomor 4
int get_median(int n[], int size)
{
    int i, j, k, min;
    int median;
    int terurut;

    for(int y=0; y < size; y++)
    {
        if(n[y] > n[y+1])
        {
            terurut = false;
        }
        else
        {
            terurut = true;
        }
    }
    if(terurut == 0)
    {
        for(i = 0; i < size; i++)
        {
            min = i;
            for(j = i+1; j < size; j++)
            {
                if(n[j] < n[min])
                {
                    min = j;
                }
            }
            k = n[i];
            n[i] = n[min];
            n[min] = k;
        }
        cout << n[size / 2] << endl;
    }
    if(terurut == 1)
    {
        cout << n[size / 2] << endl;
    }
}
