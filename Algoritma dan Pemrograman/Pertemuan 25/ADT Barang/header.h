#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

//4207 - 4208 ADT Barang

class barang{
    public:
        string nama; //variabel disebut juga atribut
        int qty, harga;
        float diskon;
        barang(string nama, int qty, int harga, float diskon)
        {
            this -> nama = nama;
            this -> qty = qty;
            this -> harga = harga;
            this -> diskon = diskon/100.0;
        }
    //prosedur atau fungsi disebut method
    void cetak() // method prosedur
    {
        cout << "Barang " << nama << " [" << qty << "] " << ": " << harga << " {diskon " << diskon << "}" << endl;
    }
    void setdiskon(int diskon) //20
    {
        if(diskon<100)
            this->diskon =diskon/100.0; //0.2
        else
            this->diskon = 0;
        //this->diskon adalah variabel diskon milik class
        //diskon adalah variabel diskon milik inputan setdiskon
    }
    /*string strdiskon() //method fungsi
    {
        return to_string(int(diskon*100))+"%"; //20.000000->20
    }*/
};
#endif // HEADER_H_INCLUDED
