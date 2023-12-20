#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Konstanta
const int MAX_RANGE = 100; // Menentukan konstanta untuk rentang maksimum angka yg akan di tebak
const int MAX_GUESSES = 10; // Menentukan konstanta untuk jumlah Maksimum untuk Tebakan angka yg ditebak pengguna

int main() {
// Tipe data
    string nama; // Menambahkan variabel untuk menyimpan nama pengguna
    int angka, random, percobaan = 0;
    int guesses[MAX_GUESSES]; // Array untuk menyimpan tebakan pengguna
    char lagi;

    cout << "    TEBAK ANGKA\n";
    cout << "--------------------\n";

    cout << "Masukkan nama Anda: ";
    getline(cin, nama);

// Perulangan
    do {
        cout << "Hai, " << nama << "! Masukkan angka antara 1-" << MAX_RANGE << "\n";
        srand(time(NULL)); // membuat bibit random
//      Operator
        random = rand() % MAX_RANGE + 1; // mengacak angka 1 - MAX_RANGE
        percobaan = 0; // reset percobaan untuk setiap bermain ulang

        do {
            cout << "Masukkan angka : ";
            cin >> angka;
// Pemilihan
            if (angka < random) {
                cout << "Angka kurang besar! \n";
            } else if (angka > random) {
                cout << "Angka kurang kecil! \n";
            } else {
                cout << "Anda benar! Anda menebak dalam " << percobaan + 1 << " percobaan.\n";
            }

            // Simpan tebakan dalam array
            if (percobaan < MAX_GUESSES) {
                guesses[percobaan] = angka;
            }

            percobaan++;
        } while (angka != random && percobaan < MAX_GUESSES);

        // Menampilkan tebakan pengguna
        cout << "Hasil Tebakan anda: ";
        for (int i = 0; i < percobaan; i++) {
            cout << guesses[i] << " ";
        }
        cout << endl;

        cout << "Main lagi? y/t = ";
        cin >> lagi;
    } while (lagi == 'y');

    return 0;
}
