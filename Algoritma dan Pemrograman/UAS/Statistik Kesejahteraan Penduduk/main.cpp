#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    cout << "Statistik Kesejahteraan Penduduk Indonesia" << endl << endl;

    int jumlah_kota;
    penduduk indonesia[10];
    cout << "Masukkan jumlah data: ";
        cin >> jumlah_kota;
    cout << endl;
    for(int n=0; n<jumlah_kota; n++){
        cout << "Kota no " << n+1 << endl;

        cout << "Nama kota \t: ";
            cin >> indonesia[n].kota;
        cout << "Daerah pulau \t: ";
            cin >> indonesia[n].pulau;
        cout << "Jumlah penduduk : ";
            cin >> indonesia[n].jumlahpen;
        cout << endl;

        cout << "Masukkan poin statistik penduduk selama 1 tahun terakhir!" << endl;
        cout << endl;

        cout << "Data Statistik Personal" << endl;
        cout << "Pendidikan \t: ";
            cin >> indonesia[n].pendidikan;
        cout << "Pendapatan \t: ";
            cin >> indonesia[n].pendapatan;
        cout << "Kesehatan \t: ";
            cin >> indonesia[n].kesehatan;
        cout << endl;

        cout << "Data Statistik Personal" << endl;
        cout << "Hubungan sosial \t: ";
            cin >> indonesia[n].hubsos;
        cout << "Keadaan lingkungan \t: ";
            cin >> indonesia[n].keadling;
        cout << "Keamanan \t\t: ";
            cin >> indonesia[n].keamanan;
        cout << endl;
    }
    for(int n=0; n<jumlah_kota; n++){
        cout << "/* Kota no " << n+1 << " */" << endl;
        indonesia[n].print();
    }
    char next;
    int opsi, nourut, nokatdata, nodata, npersonalmax, nsosialmax, nkesdupmax;
    float data_baru, jumlah=0, personalmax=0, sosialmax=0, kesdupmax=0;
    do{
        cout << "Menu opsi" << endl;
        cout << "1 - Edit data" << endl;
        cout << "2 - Analisis data" << endl;
        cout << "Masukkan opsi: ";
            cin >> opsi;
        cout << endl;
        if(opsi==1){
            cout << "Data kota no: ";
                cin >> nourut;
            nourut=nourut-1;
            cout << "Pilih kategori data yang akan diedit: " << endl;
            cout << "1. Data kota" << endl;
            cout << "2. Data statistik personal" << endl;
            cout << "3. Data statistik sosial" << endl;
            cout << "Masukkan perintah: ";
                cin >> nokatdata;
            cout << endl;
            if(nokatdata==1){
                cout << "Pilih data yang akan diedit:" << endl;
                cout << "1. Nama kota" << endl;
                cout << "2. Daerah pulau" << endl;
                cout << "3. Jumlah penduduk" << endl;
                cout << "Masukkan perintah: ";
                    cin >> nodata;
                cout << endl;
                cout << "Masukkan data baru: ";
                    cin >> data_baru;
                cout << endl;
                if(nodata==1){
                    indonesia[nourut].kota=data_baru;
                    indonesia[nourut].print();
                }
                else if(nodata==2){
                    indonesia[nourut].pulau=data_baru;
                    indonesia[nourut].print();
                }
                else{
                    indonesia[nourut].jumlahpen=data_baru;
                    indonesia[nourut].print();
                }
            }
            else if(nokatdata==2){
                cout << "Pilih data yang akan diedit:" << endl;
                cout << "1. Pendidikan" << endl;
                cout << "2. Pendapatan" << endl;
                cout << "3. Kesehatan" << endl;
                cout << "Masukkan perintah: ";
                    cin >> nodata;
                cout << endl;
                cout << "Masukkan data baru: ";
                    cin >> data_baru;
                cout << endl;
                if(nodata==1){
                    indonesia[nourut].pendidikan=data_baru;
                    indonesia[nourut].print();
                }
                else if(nodata==2){
                    indonesia[nourut].pendapatan=data_baru;
                    indonesia[nourut].print();
                }
                else{
                    indonesia[nourut].kesehatan=data_baru;
                    indonesia[nourut].print();
                }
            }
            else{
                cout << "Pilih data yang akan diedit:" << endl;
                cout << "1. Hubungan sosial" << endl;
                cout << "2. Keadaan lingkungan" << endl;
                cout << "3. Keamanan" << endl;
                cout << "Masukkan perintah: ";
                    cin >> nodata;
                cout << endl;
                cout << "Masukkan data baru: ";
                    cin >> data_baru;
                cout << endl;
                if(nodata==1){
                    indonesia[nourut].hubsos=data_baru;
                    indonesia[nourut].print();
                }
                else if(nodata==2){
                    indonesia[nourut].keadling=data_baru;
                    indonesia[nourut].print();
                }
                else{
                    indonesia[nourut].keamanan=data_baru;
                    indonesia[nourut].print();
                }
            }
        }
        else if(opsi==2){
            for(int n=0;n<jumlah_kota;n++){
                if(indonesia[n].npersonal()>personalmax){
                    personalmax=indonesia[n].npersonal();
                    npersonalmax=n;
                }
                if(indonesia[n].nsosial()>sosialmax){
                    sosialmax=indonesia[n].nsosial();
                    nsosialmax=n;
                }
                if(indonesia[n].nkesdup()>kesdupmax){
                    kesdupmax=indonesia[n].nkesdup();
                    nkesdupmax=n;
                }
            }
            cout << "/* Analisa Statistik Kesejahteraan Penduduk Indonesia */" << endl << endl;

            cout << "||=============================================================" << endl;

            cout << "   [1] Kota dengan poin statistik nilai personal tertinggi. " << endl;
            cout << "       /-> Yaitu kota " << indonesia[npersonalmax].kota << " dengan total " << personalmax << " poin" << endl << endl;

            cout << "   [2]. Kota dengan poin statistik nilai sosial tertinggi. " << endl;
            cout << "       /-> Yaitu kota " << indonesia[nsosialmax].kota << " dengan total " << sosialmax << " poin" << endl << endl;

            cout << "   [3]. Kota dengan poin kesejahteraan hidup tertinggi. " << endl;
            cout << "       /-> Yaitu kota " << indonesia[nkesdupmax].kota << " dengan total " << kesdupmax << " poin" << endl;

            cout << "||=============================================================" << endl << endl;
        }
        else{
            cout << "Menu opsi yang anda masukkan tidak dikenal / salah!" << endl;
        }
        cout << "Apakah anda ingin lanjut? (Y / N): ";
            cin >> next;
        cout << endl;
    }
    while(next=='Y');
    return 0;
}
