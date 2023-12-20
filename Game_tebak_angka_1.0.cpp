#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_RANGE = 100; // Define a constant for the maximum range
const int MAX_GUESSES = 10; // Define a constant for the maximum number of guesses

int main() {
    int angka, random, attempts = 0;
    int guesses[MAX_GUESSES]; // Array to store user guesses
    char lagi;

    cout << "TEBAK ANGKA\n";
    cout << "-------------------\n";

    do {
        cout << "Masukkan angka antara 1-" << MAX_RANGE << "\n";
        srand(time(NULL)); // membuat bibit random
        random = rand() % MAX_RANGE + 1; // mengacak angka 1 - MAX_RANGE
        attempts = 0; // reset attempts for each new game

        do {
            cout << "Masukkan angka : ";
            cin >> angka;

            if (angka < random) {
                cout << "Angka kurang besar! ";
            } else if (angka > random) {
                cout << "Angka kurang kecil! ";
            } else {
                cout << "Anda benar! Anda menebak dalam " << attempts + 1 << " percobaan.\n";
            }

            // Store the guess in the array
            if (attempts < MAX_GUESSES) {
                guesses[attempts] = angka;
            }

            attempts++;
        } while (angka != random && attempts < MAX_GUESSES);

        // Display user's guesses
        cout << "Your guesses: ";
        for (int i = 0; i < attempts; i++) {
            cout << guesses[i] << " ";
        }
        cout << endl;

        cout << "Main lagi? y/t\n";
        cin >> lagi;
    } while (lagi == 'y');

    return 0;
}

