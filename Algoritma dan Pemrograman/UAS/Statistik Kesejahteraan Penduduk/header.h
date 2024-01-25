#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

class penduduk{
    public:
        string kota, pulau;
        float jumlahpen, pendidikan, pendapatan, kesehatan, hubsos, keadling, keamanan;

    penduduk(){

    }

    float tpendidikan(){
        return pendidikan;
    }
    float tpendapatan(){
        return pendapatan;
    }
    float tkesehatan(){
        return kesehatan;
    }
    float thubsos(){
        return hubsos;
    }
    float tkeadling(){
        return keadling;
    }
    float tkeamanan(){
        return keamanan;
    }

    float npersonal(){
        return tpendidikan() + tpendapatan() + tkesehatan();
    }
    float nsosial(){
        return thubsos() + tkeadling() + tkeamanan();
    }
    float nkesdup(){
        return npersonal() + nsosial();
    }

    string ketpersonal(float npersonal){
        string catketpersonal;
        if(npersonal>=90)
            catketpersonal="sangat tinggi";
        else if(npersonal<90 && npersonal>=80)
            catketpersonal="tinggi";
        else if(npersonal<80 && npersonal>=70)
            catketpersonal="cukup";
        else if(npersonal<70 && npersonal>=60)
            catketpersonal="rendah";
        else
            catketpersonal="sangat rendah";
        return catketpersonal;
    }

    string ketsosial(float nsosial){
        string catketsosial;
        if(nsosial>=90)
            catketsosial="sangat tinggi";
        else if(nsosial<90 && nsosial>=80)
            catketsosial="tinggi";
        else if(nsosial<80 && nsosial>=70)
            catketsosial="cukup";
        else if(nsosial<70 && nsosial>=60)
            catketsosial="rendah";
        else
            catketsosial="sangat rendah";
        return catketsosial;
    }

    string ketkesdup(float nkesdup){
        string catketkesdup;
        if(nkesdup>=90)
            catketkesdup="sangat tinggi";
        else if(nkesdup<90 && nkesdup>=80)
            catketkesdup="tinggi";
        else if(nkesdup<80 && nkesdup>=70)
            catketkesdup="cukup";
        else if(nkesdup<70 && nkesdup>=60)
            catketkesdup="rendah";
        else
            catketkesdup="sangat rendah";
        return catketkesdup;
    }

    void print(){
        cout << "======================================================" << endl;

        cout << "|| Nama kota \t\t: " << kota << endl;
        cout << "|| Daerah pulau \t: " << pulau << endl;
        cout << "|| Jumlah penduduk \t: " << jumlahpen << " jiwa" << endl << endl;

        cout << "|| Data Statistik Personal" << endl;
        cout << "   -/ Pendidikan \t: " << pendidikan << endl;
        cout << "   -/ Pendapatan \t: " << pendapatan << endl;
        cout << "   -/ Kesehatan \t: " << kesehatan << endl << endl;

        cout << "|| Data Statistik Sosial" << endl;
        cout << "   -/ Hubungan sosial \t      : " << hubsos << endl;
        cout << "   -/ Keadaan lingkungan      : " << keadling << endl;
        cout << "   -/ Keamanan \t\t      : " << keamanan << endl << endl;

        float nper = npersonal() / 3;
        cout << "|| Rata-rata poin statistik personal adalah " << nper << "." << endl;
        string ketper = ketpersonal(nper);
        cout << "   -> Taraf indeks: " << ketper << endl << endl;

        float nsos = nsosial() / 3;
        cout << "|| Rata-rata poin statistik sosial adalah " << nsos << "." << endl;
        string ketsos = ketsosial(nsos);
        cout << "   -> Taraf indeks: " << ketsos << endl << endl;

        float nkd = nkesdup() / 6;
        cout << "|| Rata-rata poin statistik kesdup adalah " << nkd << "." << endl;
        string ketkd = ketkesdup(nkd);
        cout << "   -> Taraf indeks: " << ketkd << endl;

        cout << "======================================================" << endl << endl;

    }
};
#endif // HEADER_H_INCLUDED
