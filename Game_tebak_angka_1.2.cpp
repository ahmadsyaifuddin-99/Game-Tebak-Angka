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

    cout << "                                 GAME TEBAK ANGKA ^_~\n";
    cout << "-------------------------------------------------------------------------------------------\n";

    cout << "Masukkan nama Anda: ";
    getline(cin, nama);
    cout << "\n";

// Perulangan
    do {
        cout << "Hai ^_^, " << nama << "! Selamat Datang di Game Tebak Angka, Game ini dapat Mengasah Insting mu ^_^ \nSilahkan Masukkan angka antara 1-" << MAX_RANGE << "\n";
        srand(time(NULL)); // membuat bibit random
        
// Operator
        random = rand() % MAX_RANGE + 1; // mengacak angka 1 - MAX_RANGE
        percobaan = 0; // reset percobaan untuk setiap bermain ulang

        do {
            cout << "Masukkan angka : ";
            cin >> angka;
            
// Pemilihan If else
            if (angka < random) {
                cout << "Angka kurang besar! \n";
            } else if (angka > random) {
                cout << "Angka kurang kecil! \n";
            } else {
                cout << "Anda benar! Anda menebak dalam " << percobaan + 1 << " percobaan.\n";
            }

            if (percobaan < MAX_GUESSES) {
            	
// Simpan tebakan dalam array
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

// Pemilihan Switch
        // Switch statement for additional features
        char choice;
        cout << "Pilih fitur tambahan:\n";
        cout << "1. Tampilkan angka tertinggi dan terendah dan main ulang\n";
        cout << "2. Langsung Main ulang \n";
        cout << "3. Keluar\n";
        cout << "Pilih 1/2/3: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case '1':
                // Display highest and lowest guessed numbers
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
                } else {
                    cout << "Belum ada tebakan.\n";
                }
                break;

            case '2':
                // Continue to the next game
                break;

            case '3':
                // Exit the program
                cout << "Terima kasih, " << nama << "! Sampai jumpa lagi.\n";
                return 0;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (true); // Infinite loop, exit condition handled within the switch statement

    return 0;
}
