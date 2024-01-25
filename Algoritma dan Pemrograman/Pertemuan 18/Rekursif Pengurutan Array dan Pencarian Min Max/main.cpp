#include <iostream>

using namespace std;

int min2(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
    if(num1 < num2)
        return num1;
    else
        return num2;
}
int max2(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
    if(num1 > num2)
        return num1;
    else
        return num2;
}
int min_arr(int data[], int s)
{
    if(s==1)
        return data[0];
    else
        return min2(data[s-1], min_arr(data, s-1));
}

int main()
{
    cout << "(5, 7) = "<< min2(5, 7) << endl;
    cout << "(12, 3) = "<< min2(5, 7) << endl;
    cout << "(4, 9) = "<< min2(5, 7) << endl;
    cout << "(9, 2) = "<< min2(5, 7) << endl;
    cout << endl;
    cout << "(5, 7) = "<< max2(5, 7) << endl;
    cout << "(12, 3) = "<< max2(5, 7) << endl;
    cout << "(4, 9) = "<< max2(5, 7) << endl;
    cout << "(9, 2) = "<< max2(5, 7) << endl;
    cout << endl;
    int data1[]={2, 5, 7};
    int size_data1 = sizeof(data1)/sizeof(data1[0]);
    cout << "min_array(data1,size_data1) = " << min_arr(data1,size_data1) << endl;
    return 0;
}
