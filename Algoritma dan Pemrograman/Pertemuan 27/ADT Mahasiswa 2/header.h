#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

class Mahasiswa{
    public:
    string nim, nama;
    float nUts, nUas, nTugas;

    Mahasiswa()
    {
        //INI KONSTRUKTOR TANPA INPUTAN, BARUUUU
    }
    Mahasiswa(string nim, string nama, float nUts, float nUas, float nTugas)
    {
        //INI KONSTRUKTOR DENGAN INPUTAN
        this->nim = nim;
        this->nama = nama;
        this->nUts = nUts;
        this->nUas = nUas;
        this->nTugas = nTugas;
    }
   float uts()
   {
       return nUts*35/100;
   }
   float uas()
   {
       return nUas*35/100;
   }
   float tugas()
   {
       return nTugas*30/100;
   }
   float nilaiAkhir()
   {
       return uts()+uas()+tugas();
   }
   char nilaiHuruf(float nilaiAkhir)
   {
       char nHuruf;
       if(nilaiAkhir>=85)
            nHuruf='A';
       else if(nilaiAkhir>=70 && nilaiAkhir<85)
            nHuruf='B';
       else if(nilaiAkhir>=60 && nilaiAkhir<70)
            nHuruf='C';
       else if(nilaiAkhir>=40 && nilaiAkhir<60)
            nHuruf='D';
       else
            nHuruf='E';
       return nHuruf;
   }
   string predikat(char nHuruf)
   {
       string p;
       switch(nHuruf)
       {
           case 'A':p="Apik"; break;
           case 'B':p="Baik"; break;
           case 'C':p="Cukup"; break;
           case 'D':p="Dablek"; break;
           default:p="Elek";
       }
       return p;
   }
   void print()
   {
       cout << "===============================\n";
       cout << "|| NIM \t\t= " << nim << endl;
       cout << "|| Nama \t= " << nama << endl;
       cout << "|| Nilai Uts \t= " << nUts << " 35% : " << uts() << endl;
       cout << "|| Nilai Uas \t= " << nUas << " 35% : " << uas() << endl;
       cout << "|| Nilai Tugas \t= " << nTugas << " 30% : " << tugas() << endl;
       float na = nilaiAkhir();
       cout << "|| Nilai Akhir \t= " << na << endl;
       char nh = nilaiHuruf(na);
       cout << "|| Nilai Huruf \t= " << nh << endl;
       string p = predikat(nh);
       cout << "|| Predikat \t= " << p << endl;
       cout << "===============================\n";
   }
};


#endif // HEADER_H_INCLUDED
