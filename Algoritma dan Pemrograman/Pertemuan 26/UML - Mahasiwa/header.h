#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>


using namespace std;
class mahasiswa{
    public:
        string nim, nama, keterangan;
        float nUTS, nUAS, nTugas, rata2;
        char prednilai;
        mahasiswa(string nama, string nim, float nTugas, float nUTS, float nUAS)
        {
            this -> nama = nama;
            this -> nim = nim;
            this -> nTugas = nTugas;
            this -> nUTS = nUTS;
            this -> nUAS = nUAS;
            this -> rata2 = (nTugas + nUTS + nUAS) / 3;
                if(rata2>=85 && rata2<=100){
                    prednilai = 'A';
                    keterangan = "Nilai anda cumlaude";
                }
                else if(rata2<85 && rata2>=70){
                    prednilai = 'B';
                    keterangan = "Nilai anda baik";
                }
                else if(rata2<70 && rata2>=55){
                    prednilai = 'C';
                    keterangan = "Nilai anda cukup";
                }
                else if(rata2<55 && rata2>=40){
                    prednilai = 'D';
                    keterangan = "Nilai anda kurang";
                }
                else{
                    prednilai = 'E';
                    keterangan = "Nilai anda sangat kurang";
                }
        }
    void cetak()
    {
        cout << "Nama: " << nama << endl
        << "Nim: " << nim << endl
        << "Nilai tugas: " << nTugas << endl
        << "Nilai UTS: " << nUTS << endl
        << "Nilai UAS " << nUAS << endl
        << "Nilai total rata-rata: " << rata2 << endl
        << "Predikat nilai: " << prednilai << endl
        << "Keterangan: " << keterangan << endl;
    }
};
#endif // HEADER_H_INCLUDED
