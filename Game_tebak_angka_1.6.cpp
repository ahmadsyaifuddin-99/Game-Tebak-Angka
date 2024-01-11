#include <iostream>
#include <string>
// Menambahkan 2 Header cstdlib dan ctime
#include <cstdlib>
#include <ctime>

using namespace std;

// Konstanta
const int MAX_RANGE = 100; // Menentukan konstanta untuk rentang maksimum angka yg akan di tebak user/pengguna
const int MAX_GUESSES = 15; // Menentukan konstanta untuk jumlah Maksimum untuk Tebakan angka yg ditebak pengguna

int main() {
    // Tipe data
    string nama; // Menambahkan variabel untuk menyimpan nama pengguna
    int angka, random, percobaan = 0; //untuk menangkap ataupun membuat Berupa Tipe data Angka Integer
    int guesses[MAX_GUESSES]; // Array untuk menyimpan tebakan pengguna
    char choice; //untuk mengdeklarasikan nilai pemilihan pada Switch
    
    
    // Mulai !
    cout << "                                                  GAME TEBAK ANGKA ^_~\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";

    cout << "Masukkan nama Anda: ";
    getline(cin, nama); // Mengambil atau Mendapatkan sebuah Inputan berupa string yg nanti akan di tampilkan
    cout << "\n";

    // Perulangan
    do {
        time_t start_time, end_time;
        time(&start_time);

        cout << "Hai ^_^, " << nama << "! Selamat Datang di Game Tebak Angka, Game ini dapat Mengasah Insting mu ^_^ \nSilahkan Masukkan angka antara 1-" << MAX_RANGE << "\n";
        srand(time(NULL)); // membuat bibit/angka random

        random = rand() % MAX_RANGE + 1; // mengacak angka 1 - MAX_RANGE
        percobaan = 0; // reset percobaan untuk setiap bermain ulang

        do {
            cout << "Masukkan angka : ";
            cin >> angka;
            cout << "\n";

            if (angka < random) { //apabila angka yg dimasukkan terlalu kecil (kurang dari angka yg dibuat oleh sistem) maka akan menampilkan 'Angka kurang besar' 
                cout << "Angka kurang besar! \n";
            } else if (angka > random) {
                cout << "Angka kurang kecil! \n";
            } else {
                time(&end_time); // membuat Perhitungan Waktu yg dibutuhkan oleh Pemain dalam menebak angka
                cout << "Anda benar! ^_^, Anda menebak dalam " << percobaan + 1 << " percobaan.\n";
                cout << "Waktu yang dibutuhkan untuk Menebak Angka: " << difftime(end_time, start_time) << " Detik\n";
            }

		// Melakukan Pengecekan Berapa jumlah angka yang telah user/pemain dalam melakukan tebakan

            if (percobaan < MAX_GUESSES) {
                guesses[percobaan] = angka; // Simpan tebakan dalam array
            }

            percobaan++;
        } while (angka != random && percobaan < MAX_GUESSES); /* untuk melakukan perulangan selama angka yang ditebak oleh pengguna
		belum sama dengan angka acak yang dihasilkan oleh program, dan jumlah percobaan belum mencapai batas maksimum. */

        // Menampilkan tebakan pengguna
        cout << "Hasil Tebakan anda: ";
        for (int i = 0; i < percobaan; i++) {
            cout << guesses[i] << " ";
        }
        cout << "\n";
        cout << "\n";
        cout << endl;

        // Pemilihan Switch
//        cout << "Pilih fitur tambahan:\n";
        cout << "1. Tampilkan angka tertinggi\n";
        cout << "2. Melanjutkan Permainan\n";
        cout << "3. Keluar\n";
        cout << "Pilih 1/2/3: ";
        cin >> choice;
        cout << "\n";
        cout << "\n";

        switch (choice) {
            case '1':
        // Menampilkan Tebakan Angka Tertinggi dan Terendah

                if (percobaan > 0) {
                    int highest = guesses[0];
                    int lowest = guesses[0];

                    for (int i = 1; i < percobaan; i++) {
                        if (guesses[i] > highest) {
                            highest = guesses[i];
                        } else if (guesses[i] < lowest) {
                            lowest = guesses[i];
                        }
                    }

                    cout << "Angka tertinggi yang ditebak: " << highest << endl;
                    cout << "Angka terendah yang ditebak: " << lowest << endl;
                    cout << "\n";

                    // Nested if untuk pilihan case no 2 dan no 3
                    cout << "Pilih langkah selanjutnya:\n";
                    cout << "1. Melanjutkan Permainan\n";
                    cout << "2. Keluar\n";
                    cout << "Pilih 1/2: ";
                    cin >> choice;
                    cout << "\n";

                    if (choice == '1') {
                        // Melanjutkan Permainan
                    } else if (choice == '2') {
                        // Keluar dari program
                        cout << "Terima kasih ^_~, " << nama << "! Sampai jumpa lagi.\n";
                        return 0;
                    } else {
                        cout << "Pilihan tidak valid.\n";
                        return 0;
                    }
                } else {
                    cout << "Belum ada tebakan.\n";
                }
                break;

            case '2':
                // Melanjutkan Permainan
                break;

            case '3':
                // Keluar dari program
                cout << "Terima kasih ^_~, " << nama << "! Sampai jumpa lagi.\n";
                return 0;

            default:
                cout << "Pilihan tidak valid.\n";
                return 0;
        }

    } while (true);

    return 0;
}
