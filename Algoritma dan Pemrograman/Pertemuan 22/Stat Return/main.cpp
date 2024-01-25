#include <iostream>

using namespace std;

void print_array(int *data, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
int *gen_return(int size)
{
    int *result = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        result[i] = i+1;
    }
    return result;
}

int *stat_return(int *data, int s) {
    int *result = (int *)malloc(4 * sizeof(int));
    int min = data[0];
    int max = data[0];
    int sum = 0;
    for (int i = 0; i < s; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
        if (data[i] > max)
        {
            max = data[i];
        }
        sum += data[i];
    }
    result[0] = min;
    result[1] = max;
    result[2] = sum;
    result[3] = sum / s;
    return result;
}

int main()
{
    int*p_array = (int *)malloc(10 * sizeof(int));
    p_array[0] = 8;
    p_array[8] = 19;

    printf("%d\n", p_array[0]);
    printf("%d\n", p_array[8]);

    p_array = (int *)malloc(20 * sizeof(int));
    p_array[15] = 99;
    printf("%d\n", p_array[15]);
    printf("%d\n", p_array[5]);

    int arr1[] = {78, 96, 57, 99, 19};
    print_array(arr1, 5);

    int *arrPtr = gen_return(25);
    print_array(arrPtr, 25);


    cout << "Stat return\n";
    int angkaStat[3] = {13,25,4};
    int *arrStat = stat_return(angkaStat, 3);
    print_array(arrStat, 4);

    return 0;
}
