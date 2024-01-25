#include <iostream>

using namespace std;
//add_rec
int add_rec(int a, int b)
{
    if(b==0){
        cout << a << " = ";
        return a;
    }
    else{
        cout << 1 << " + ";
        return 1 + add_rec(a,(b-1));
    }
}
int main()
{
    cout << "add rec 3,4 = " << add_rec(3,4);
}
