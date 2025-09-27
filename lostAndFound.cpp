/*
    Nama Lengkap : Amela Luna Andrealova
    NIM : 25/566386/TK/63891
    Kelompok : Deimos 
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string kata, sandi;
    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // menghilangkan vowels dan membalikkan huruf
    for(int i = kata.length() - 1; i >= 0; i--){
        char ch = kata[i];
        if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
            sandi += kata[i];
        }
    }

    // memasukkan kode ASCII huruf pertama ditengah sandi
    if(!sandi.empty()){
        int ascii = static_cast<int>(kata[0]);
        int mid = sandi.length() / 2;
        sandi.insert(mid, to_string(ascii));
    }

    cout << "Sandi: " << sandi << endl;
    return 0;
}

