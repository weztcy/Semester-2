#include <iostream>
#include <math.h>

using namespace std;

//ADT abstract data type /tipe data bentukan

 typedef struct struct_koordinat { //typedef uintuk mempersingkat
    float x, y;//atribut

    void terbentuk();
}koordinat;
//prosedur milik koordinat
void koordinat::terbentuk()
{

    cout<<"koordinat terbentuk\n";
}
float jarak (koordinat k1, koordinat k2) //fungsi bebas
{
    float j = pow(k2.x - k1.x,2) + pow ((k2.y -k1.y),2);
    return sqrt(j);
}
void koordinatnegatif( koordinat &k) //prosedur bebas
{
    k.x = -k.x;
    k.y = -k.y;
}
string kuadran(koordinat k) //fungsi bebas
{
    string ket;
    if(k.x>0 && k.y>0)
        ket = "kuadran 1" ;
    else if (k.x<0 && k.y>0)
        ket = "kuadran 2";
    else if (k.x<0 && k.y<0)
        ket = "kuadran 3";
    else
        ket = "kuadran 4";
    return ket;

}

int main()
{
    //membuat variabel
    koordinat A; //int a;
    A.terbentuk(); //prosedur nya A
    A.x = 3;// A =3; //atribut  A
    A.y = 4; // atrubut A

    cout << "koordinat A = { " << A.x << ","<< A.y<< "}"<< endl;
    koordinat B = {6,8}; //atributnya B
    B.terbentuk(); //prosedur nya A
    cout << "koordinat B = { " << B.x << ","<< B.y<< "}"<< endl;
    cout << "jarak AB = " << jarak(A,B) << endl;

    koordinatnegatif(A);
    cout << "koordinat A = { " << A.x << ","<< A.y<< "}"<< endl;
    cout << "koordinat A terletak di " <<kuadran(A)<<endl;
    cout << "koordinat B terletak di " <<kuadran(B)<<endl;
    return 0;
}
