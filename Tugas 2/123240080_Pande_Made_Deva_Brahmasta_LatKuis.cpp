#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
#define maxsize 1000

// struct
struct food
{
    string negara;
    string tempat;
    string nama;
    int harga;
};
struct profile
{
    string username[maxsize];
    string password[maxsize];
    int totalFood = 0;
    int totalUser;
};

// global declare
char loginChoice, menuChoice;
profile user;
food makanan[maxsize];

// function declare
void userRegis();
void userLogin();
void loginMenu();
void mainMenu();
void recordMenu();
void viewMenu();
void searchMenu();
void totalMenu();
void exitMenu();
void pause();
int rekTotalPrice(int totalHarga, int sum);

int main()
{
    loginMenu();
}

void pause()
{
    cout << "Tekan apapun untuk melanjutkan...";
    getch();
}

void loginMenu()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(2) << " " << "Selamat Datang di Pencatatan Makanan" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "[1] Register" << endl;
    cout << "[2] Login" << endl;
    cout << "[3] Exit" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih  : ";
    cin >> loginChoice;
    pause();
    switch (loginChoice)
    {
    case '1':
        userRegis();
        break;
    case '2':
        userLogin();
        break;
    case '3':
        exitMenu();
        break;

    default:
        cout << "Pilihan tidak tersedia" << endl;
        pause();
        loginMenu();
        break;
    }
}

void userRegis()
{
    system("cls");
    string usname, pass;
    char ulang;
    bool regis = true;

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "Registrasi" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Username : ";
    cin >> usname;
    cout << "Password : ";
    cin >> pass;

    if (user.totalUser >= maxsize)
    {
        cout << "\nMaaf, user sudah mencapai batas maksimal" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        exitMenu();
    }

    for (int i = 0; i < user.totalUser; i++)
    {
        if (user.username[i] == usname)
        {
            regis = false;
            break;
        }
    }
    if (regis == false)
    {
        cout << "\nMaaf, username sudah terdaftar" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        pause();
        loginMenu();
    }
    else
    {
        user.username[user.totalUser] = usname;
        user.password[user.totalUser] = pass;
        user.totalUser++;

        cout << "\nRegistrasi berhasil" << endl
             << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        pause();
        loginMenu();
    }
}
int chancelogin = 3;

void userLogin()
{
    system("cls");
    string usname, pass;
    bool login = false;

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "Login" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    if (user.totalUser == 0)
    {
        cout << "\nAnda belum melakukan registrasi," << endl
             << "Silahkan registrasi terlebih dahulu" << endl
             << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        pause();
        loginMenu();
    }
    cout << "Username : ";
    cin >> usname;
    cout << "Password : ";
    cin >> pass;

    for (int i = 0; i < user.totalUser; i++)
    {
        if (usname == user.username[i] && pass == user.password[i])
            login = true;
    }
    if (login == true)
    {
        cout << "\nLogin berhasil, Selamat datang " << usname << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        pause();
        mainMenu();
    }
    else
    {
        if (chancelogin <= 0)
        {
            cout << "Kesempatan login habis, silahkan coba lagi nanti" << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            pause();
            exitMenu();
        }
        chancelogin--;
        cout << "\nUsername atau password salah, \nkesempatan login tersisa " << chancelogin << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        pause();
        userLogin();
    }
}

void mainMenu()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(9) << " " << "Menu Pencatatan Makanan" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "[1] Mencatat Makanan" << endl;
    cout << "[2] Melihat Makanan" << endl;
    cout << "[3] Mencari Makanan" << endl;
    cout << "[4] Total Harga Makanan" << endl;
    cout << "[5] Exit" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih  : ";
    cin >> menuChoice;
    pause();
    switch (menuChoice)
    {
    case '1':
        recordMenu();
        break;
    case '2':
        viewMenu();
        break;
    case '3':
        searchMenu();
        break;
    case '4':
        totalMenu();
        break;
    case '5':
        exitMenu();
        break;

    default:
        cout << "Pilihan tidak tersedia" << endl;
        pause();
        mainMenu();
        break;
    }
}

void recordMenu()
{
    char ulang;
    int quantity;
    bool invalid = false;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(9) << " " << "Menu Pencatatan Makanan" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Ingin mencatat berapa makanan : ";
    cin >> quantity;
    cin.ignore();
    for (int i = user.totalFood; i < user.totalFood + quantity; i++)
    {
        cout << "Makanan ke-" << (i + 1) << endl;
        cout << "Negara         : ";
        getline(cin, makanan[i].negara);
        cout << "Tempat Makanan : ";
        getline(cin, makanan[i].tempat);
        cout << "Nama Makanan   : ";
        getline(cin, makanan[i].nama);
        cout << "Harga Makanan  : ";
        cin >> makanan[i].harga;
        cin.ignore();
        cout << endl;
    }

    user.totalFood += quantity;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Data sudah dicatat" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    do
    {
        cout << "Ingin kembali ke menu? (y/n) : ";
        cin >> ulang;
        if (ulang == 'y' || ulang == 'Y')
            mainMenu();
        else if (ulang == 'n' || ulang == 'N')
            recordMenu();
        else
            cout << "Pilihan tidak tersedia, coba lagi" << endl;
        invalid = true;
    } while (invalid == true);
}

void viewMenu()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(2) << " " << "Menu Melihat Makanan" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < user.totalFood; i++)
    {
        cout << "Makanan ke-" << (i + 1) << endl;
        cout << "Negara         : " << makanan[i].negara << endl;
        cout << "Tempat Makanan : " << makanan[i].tempat << endl;
        cout << "Nama Makanan   : " << makanan[i].nama << endl;
        cout << "Harga Makanan  : " << makanan[i].harga << endl;
        cout << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl;
    pause();
    mainMenu();
}

void searchMenu()
{
    bool invalid = false;
    system("cls");
    string cari;
    char ulang;

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(2) << " " << "Menu Mencari Makanan" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cin.ignore();
    cout << "Masukkan nama makanan yang dicari : ";
    getline(cin, cari);
    makanan[user.totalFood].nama = cari;

    int i = 0;
    while (makanan[i].nama != cari)
        i++;

    if (i >= user.totalFood)
    {
        cout << "\nMakanan tidak ditemukan" << endl;
    }
    else
    {
        cout << "\nMakanan ditemukan pada catatan ke-" << i + 1 << endl;
        cout << "Negara         : " << makanan[i].negara << endl;
        cout << "Tempat Makanan : " << makanan[i].tempat << endl;
        cout << "Nama Makanan   : " << makanan[i].nama << endl;
        cout << "Harga Makanan  : " << makanan[i].harga << endl;
    }
    cout << endl
         << setfill('=') << setw(40) << "=" << endl;

    do
    {
        cout << "Ingin kembali ke menu? (y/n) : ";
        cin >> ulang;
        if (ulang == 'y' || ulang == 'Y')
            mainMenu();
        else if (ulang == 'n' || ulang == 'N')
            searchMenu();
        else
            cout << "Pilihan tidak tersedia, coba lagi" << endl;
        invalid = true;
    } while (invalid == true);
}

int rekTotalPrice(int totalHarga, int sum)
{

    if (sum == 0)
        return totalHarga;
    else
        return (rekTotalPrice(totalHarga + makanan[sum - 1].harga, sum - 1));
}

void totalMenu()
{
    system("cls");
    int totalHarga = 0, sum;
    char ulang;
    bool invalid = false;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(2) << " " << "Menu Total Harga Makanan" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    cout << "Total makanan yang dicatat : " << user.totalFood << endl;
    cout << "Input berapa data yang ingin anda jumlahkan : ";
    cin >> sum;
    if (sum > user.totalFood)
    {
        cout << "\nData yang ingin dijumlahkan melebihi total data yang dicatat" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        pause();
        totalMenu();
    }
    totalHarga = rekTotalPrice(totalHarga, sum);
    cout << "Total harga makanan : " << totalHarga << endl;
    cout << endl
         << setfill('=') << setw(40) << "=" << endl;

    do
    {
        cout << "Ingin kembali ke menu? (y/n) : ";
        cin >> ulang;
        if (ulang == 'y' || ulang == 'Y')
            mainMenu();
        else if (ulang == 'n' || ulang == 'N')
            totalMenu();
        else
            cout << "Pilihan tidak tersedia, coba lagi" << endl;
        invalid = true;
    } while (invalid == true);
}

void exitMenu()
{
    cout << endl
         << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << " Terimakasih telah memakai sistem kami.." << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    exit(0);
}