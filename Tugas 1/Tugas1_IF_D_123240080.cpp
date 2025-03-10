#include <iostream>
using namespace std;

int ganjil(int awal, int akhir, int hasil)
{
    if (awal % 2 == 0 && awal <= akhir)
    {
        return ganjil(awal + 1, akhir, hasil);
    }
    else if (awal % 2 == 1 && awal <= akhir)
    {
        hasil+=awal;
        cout << awal;
        if (awal + 2 <= akhir)
        {
            cout << " + ";
        }
        return ganjil(awal + 1, akhir, hasil);
    }
    cout << " = " << hasil;
    return hasil;
}


int genap(int awal, int akhir, int hasil)
{
    if (awal % 2 == 1 && awal <= akhir)
    {
        return genap(awal + 1, akhir, hasil);
    }
    else if (awal % 2 == 0 && awal <= akhir)
    {
        hasil+=awal;
        cout << awal;
        if (awal + 2 <= akhir)
        {
            cout << " + ";
        }
        return genap(awal + 1, akhir, hasil);
    }
    cout << " = " << hasil;
    return hasil;
}

int main()
{
    system("cls");
    int awal, akhir, hasil = 0;
    char pilihan;
    string ulang;
    bool ulangPilihan = true;

    cout << "Masukkan bilangan awal : ";
    cin >> awal;
    cout << "Masukkan bilangan akhir : ";
    cin >> akhir;
    cout << endl
         << "[+] Deret ganjil " << endl
         << "[-] Deret genap ";

    do
    {
        cout << "\nPilihan anda (+/-)  : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '+':
            ganjil(awal, akhir, hasil);
            ulangPilihan = false;
            break;
        case '-':
            genap(awal, akhir, hasil);
            ulangPilihan = false;
            break;

        default:
            cout << "\nMohon masukkan ulang pilihan yang benar";
            ulangPilihan = true;
            break;
        }
    }while (ulangPilihan == true);
    
    cout << endl << endl;
    do
    {
        cout << "Ingin menghitung kembali? (y/n) : ";
        cin >> ulang;
    } while (ulang != "y" && ulang != "Y" && ulang != "n" && ulang != "N" );    
    if (ulang == "y" || ulang == "Y")
    {
        system("pause");
        main();
    }

}