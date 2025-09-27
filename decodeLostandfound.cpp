/*
    Nama Lengkap : Amela Luna Andrealova
    NIM : 25/566386/TK/63891
    Kelompok : Deimos 
*/

#include <iostream>
#include <string>
#include <cctype> // untuk isdigit
#include <algorithm> // untuk remove_if

using namespace std;

// Fungsi untuk membuat sandi (Encode)
string encode(string kata) {
    if (kata.empty()) return "";

    string sandi;
    char hurufPertama = kata[0]; // Simpan huruf pertama sebelum loop

    // menghilangkan vowels dan membalikkan huruf
    for (int i = kata.length() - 1; i >= 0; i--) {
        char ch = tolower(kata[i]); // Ubah ke lowercase untuk perbandingan
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            sandi += kata[i]; // Tambahkan karakter asli (mempertahankan case)
        }
    }

    // memasukkan kode ASCII huruf pertama ditengah sandi
    if (!sandi.empty()) {
        int ascii = static_cast<int>(hurufPertama);
        int mid = sandi.length() / 2;
        sandi.insert(mid, to_string(ascii));
    }
    return sandi;
}

// Fungsi untuk memecahkan sandi (Decode Tanpa Vowels)
string decode(string sandi) {
    string angkaAscii, konsonan;

    // 1. Pisahkan angka dari huruf
    for (char ch : sandi) {
        if (isdigit(ch)) {
            angkaAscii += ch;
        } else {
            konsonan += ch;
        }
    }

    if (angkaAscii.empty()) {
        return "Sandi tidak valid (tidak ada kode ASCII)";
    }

    // 2. Ubah string angka ke integer, lalu ke karakter
    char hurufPertama = static_cast<char>(stoi(angkaAscii));

    // 3. Balikkan urutan konsonan
    reverse(konsonan.begin(), konsonan.end());

    // 4. Gabungkan
    string hasilDecode = "Huruf pertama: " + string(1, hurufPertama) + "\n";
    hasilDecode += "Urutan konsonan (terbalik): " + konsonan + "\n";

    return hasilDecode;
}


int main() {
    int pilihan;
    cout << "Pilih mode:\n1. Encode (Buat Sandi)\n2. Decode (Pecahkan Sandi)\nPilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        string kata;
        cout << "Masukkan sebuah kata: ";
        cin >> kata;
        string hasilSandi = encode(kata);
        cout << "Sandi: " << hasilSandi << endl;
    } else if (pilihan == 2) {
        string sandi;
        cout << "Masukkan sandi untuk di-decode: ";
        cin >> sandi;
        string hasilDecode = decode(sandi);
        cout << "--- Hasil Decode ---\n" << hasilDecode << endl;


    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;

}
