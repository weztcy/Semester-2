#include <iostream>
#include "header.h"
using namespace std;

//4207 - 4208 ADT Barang

int main()
{
    barang laptop{"ROG 15 Inch",10,20000000,20}; //objek
    /*laptop.nama = "ROG 15 Inch";
    laptop.qty = 10;
    laptop.harga = 20000000;
    //laptop.diskon = 20; //mengisi dari atribut
    laptop.setdiskon(20);*/
    laptop.cetak(); //memanggil method prosedur

    /*barang keyboard; //objek
    keyboard.nama = "Corsair K100";
    keyboard.qty = 10;
    keyboard.harga = 3300000;
    //keyboard.diskon = 20; //mengisi dari atribut
    keyboard.setdiskon(40);
    keyboard.cetak(); //memanggil method prosedur

    barang mouse; //objek
    mouse.nama = "Logitech G512";
    mouse.qty = 10;
    mouse.harga = 1200000;
    //mouse.diskon = 20; //mengisi dari atribut
    mouse.setdiskon(10);
    mouse.cetak(); //memanggil method prosedur*/
    return 0;
}
