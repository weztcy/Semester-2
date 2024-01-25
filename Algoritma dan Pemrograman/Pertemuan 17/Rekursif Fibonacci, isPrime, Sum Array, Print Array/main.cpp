#include <iostream>

using namespace std;

int kali (int a, int b)
{
    if(b==1){
        cout << a << " = ";
        return a; //basis
    }
    else
    {
        cout << a << " + ";
        return a + kali(a,b-1); //rekursif
    }
}

int pangkat(int a, int b)
{
    if(b==1)
        return a; //basis
    else
        return a * pangkat(a,b-1); //rekursif
}

//2^3 = 2*2*2
//a^b = a*a*a --> diulang sebanyak b
//    = a*(a*b-1)

int faktorial(int n)
{
    if(n==0){
        cout << 0 << " = ";
        return 0; //basis 0
    }
    if(n==1){
        cout << 1 << " = ";
        return 1; //basis 1
    }
    else{
        cout << n << " x ";
        return n * faktorial(n-1); //rekursif
    }
}

int fibonacci(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int isprime(int i, int num) //bilangan prima itu hanya bilangan yang bisa dibagi angka 1 dan bilangannya sendiri
{
    if(num==i)
        return 1; //true
    else if(num%i==0) //habis dibagi
        return 0; //false
    else
        return isprime(i+1,num);
}

int sum_array(int data[], int s)
{
    if(s<=0){
        cout << " = ";
        return 0;
    }

    else{
        cout << data[s-1] << " + ";
        return sum_array(data, s-1) + data[s-1];
    }
}

void print_array(int data[], int start, int s)
{
    if(start==s){
        return;
    }
    else{
        cout << data[start] << " ";
        print_array(data, start+1, s);
    }
}

int min2(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}

int max2(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int main()
{
    cout << "3 * 4 = " << kali(3,4) << endl;
    cout << "2 ^ 3 = " << pangkat(2,3) << endl;
    cout << "3! = " << faktorial(3) << endl;
    cout << "0! = " << faktorial(0) << endl;
    cout << "fibonacci (4) = " << fibonacci(4) << endl;
    cout << "isprime(2,5) = " << isprime(2,5) << endl;
    cout << "isprime(2,4) = " << isprime(2,4) << endl;
    cout << "min2(9,2)" << min2(9,2) << endl;
    cout << "max2(5,7)"<< max2(5,7) << endl;

    int data1[]={2,5,7};
    int size_data1 = sizeof(data1)/sizeof(data1[0]);
    cout << "sum_array(data1,size_data1) = " << sum_array(data1,size_data1) << endl;
    print_array(data1,0,size_data1);
    return 0;
}
