/*
    Nama        : 
    NIM         : 
    Kelompok    : 
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//deklarasi fungsi utama
int balikDigit(int angka) {
    // Jika angka adalah 0, langsung kembalikan 0
    if (angka == 0) {
        return 0;
    }

    // Case simpan tanda negatif 
    bool isNegatif = (angka < 0);
    int n = abs((int)angka);
    int hasilBalik = 0;

    // Loop untuk membalik digit
    while (n > 0) {
        int digit = n % 10; // Ambil digit terakhir
        hasilBalik = hasilBalik * 10 + digit; // Tambahkan ke hasil
        n = n / 10; // Hapus digit terakhir dari angka asli
    }

    // Kembalikan tanda negatif jika angka aslinya negatif
    if (isNegatif) {
        hasilBalik = -hasilBalik;
    }

    return static_cast<int>(hasilBalik);
}

int main() {
    // Array sesuai soal
    vector<int> deret = {204, 18, -917, 500, 9};
    int totalJumlah = 0;

    cout << "Deret Awal: [";
    for (size_t i = 0; i < deret.size(); ++i) {
        cout << deret[i] << (i == deret.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl << endl;

    cout << "Proses Transformasi:" << endl;

    // Loop untuk memproses setiap elemen dalam deret
    for (size_t i = 0; i < deret.size(); ++i) {
        int nilaiSekarang = deret[i];
        
        // Cek apakah indeks 'i' adalah genap
        if (i % 2 == 0) {
            int nilaiSetelahBalik = balikDigit(nilaiSekarang);
            cout << "Indeks " << i << " (Genap): Angka " << nilaiSekarang << " diubah menjadi " << nilaiSetelahBalik << endl;
            totalJumlah += nilaiSetelahBalik;
        } else { // Jika indeks ganjil
            cout << "Indeks " << i << " (Ganjil): Angka " << nilaiSekarang << " tidak berubah" << endl;
            totalJumlah += nilaiSekarang;
        }
    }

    cout << "Total jumlah setelah transformasi adalah: " << totalJumlah << endl;

    return 0;
}