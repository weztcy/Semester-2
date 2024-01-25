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

int main()
{
    cout << "3 * 4 = " << kali(3,4) << endl;
    cout << "2 ^ 3 = " << pangkat(2,3) << endl;
    cout << "3! = " << faktorial(3) << endl;
    cout << "0! = " << faktorial(0) << endl;
    return 0;
}
