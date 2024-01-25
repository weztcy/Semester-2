#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    /*Mahasiswa Dilan{"A11.123", "Dilan", 100, 100, 100};
    Dilan.print();
    Mahasiswa Milea{"A11.124", "Milea", 70, 80, 100};
    Milea.print();*/
    //Memanggil konstruktor dengan inputan

    int jml_mhs, pil;
    Mahasiswa mhs[40]; //pesan objek 40 tempat
    //Memanggil konstruktor tanpa inputan
    cout << "masukkan banyak mahasiswa = ";
    cin >> jml_mhs;
    for(int i=0 ; i<jml_mhs ; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Masukkan NIM (Tanpa spasi) = ";
        cin >> mhs[i].nim;
        cout << "Masukkan Nama = ";
        cin >> mhs[i].nama;
        cout << "Masukkan Nilai UTS = ";
        cin >> mhs[i].nUts;
        cout << "Masukkan Nilai UAS = ";
        cin >> mhs[i].nUas;
        cout << "Masukkan Nilai Tugas = ";
        cin >> mhs[i].nTugas;
    }
    for(int i=0; i<jml_mhs; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        mhs[i].print();
    }
    char lanjut;
    int urutan, pilNil;
    float nilaiBaru;
    float nMax=0, nMin=100, jml=0, rata=0;
    int iMax, iMin;
    do{
        cout << "Pilihan\n1. Update nilai\n2. Analisa data\n"
                << "Masukkan pilihan = ";
        cin >> pil;
        if(pil==1){
            cout << "Mahasiswa urutan ke = ";
            cin >> urutan;
            urutan = urutan-1;
            cout << "Nilai yang ingin diupdate\n1. Nilai UAS\n2. Nilai Tugas";
            cin >> pilNil;
            cout << "Masukkan nilai baru = ";
            cin >> nilaiBaru;
            if(pilNil == 1){
                mhs[urutan].nUas = nilaiBaru;
            }
            else{
                mhs[urutan].nTugas = nilaiBaru;
                mhs[urutan].print();
            }
        }
        else if (pil==2){
            for(int i=0; i < jml_mhs; i++){
                jml += mhs[i].nilaiAkhir();
                if(mhs[i].nilaiAkhir() > nMax){
                    nMax = mhs[i].nilaiAkhir();
                    iMax = i;
                }
                if(mhs[i].nilaiAkhir() < nMin){
                    nMin = mhs[i].nilaiAkhir();
                    iMin= i;
                }
            }
            cout << "Analisa berdasarkan nilai akhir mahasiswa\n";
            cout << "Nilai tertinggi " << nMax << " diperoleh mahasiwa "
                    << mhs[iMax].nama<< endl;
            cout << "Nilai terendah " << nMin << " diperoleh mahasiwa "
                    << mhs[iMin].nama<< endl;
            rata = jml/jml_mhs;
            cout << "Nilai rata-rata = " << rata << endl;
        }
        else{
            cout << "Inputan anda salah.\n";
        }
        cout << "Apakah ingin lanjut (y/n)? ";
        cin >> lanjut;
    } while(lanjut == 'y');

    return 0;
}
