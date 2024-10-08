

#include <iostream>
#include "kelE.h"

using namespace std;

int main() {
    // Deklarasi variable List. Nama variable List adalah huruf pertama pada nama lengkap Anda dan huruf terakhir nama lengkap anggota tim Anda.
    infotype A,B,C,D,E,F;
    List Y;
    address S;
    int Data_Ke;
    address Prev;

    // 01. Meng-create list
    Create_List(Y);

    // Meminta user data pertama yang akan dimasukkan ke list
    cout << "Masukkan data pertama:" << endl;
    cout << "Nama: ";
    getline(cin, A.nama);
    cout << "Lama Kerja: ";
    cin >> A.lamaKerja;
    cin.ignore();
    cout << "Jabatan: ";
    getline(cin, A.jabatan);
    cout << "Departemen: ";
    getline(cin, A.departemen);
    cout << "Status: ";
    getline(cin, A.status);
    cout << "Gaji: ";
    cin >> A.gaji;
    cin.ignore();



    // 02. Melakukan create new elemen berdasarkan data yang diinputkan user
    S = New_Elemen(A);

    // 03. Memanggil salah satu jenis insert (jangan insert after)
    Insert_First(Y, S);


    // Meminta user data kedua yang akan dimasukkan ke list
    cout << "Masukkan data kedua:" << endl;
    cout << "Nama: ";
    getline(cin, B.nama);
    cout << "Lama Kerja: ";
    cin >> B.lamaKerja;
    cin.ignore();
    cout << "Jabatan: ";
    getline(cin, B.jabatan);
    cout << "Departemen: ";
    getline(cin, B.departemen);
    cout << "Status: ";
    getline(cin, B.status);
    cout << "Gaji: ";
    cin >> B.gaji;
    cin.ignore();

    // 04. Melakukan create new elemen berdasarkan data yang diinputkan user
    S = New_Elemen(B);

    // 05. Memanggil salah satu jenis insert (berbeda dengan insert yang data pertama, jangan Insert after)
    Insert_Last(Y, S);
    Show(Y);


    // Meminta user data ketiga yang akan dimasukkan ke list
    cout << "Masukkan data ketiga:" << endl;
    cout << "Nama: ";
    getline(cin, C.nama);
    cout << "Lama Kerja: ";
    cin >> C.lamaKerja;
    cin.ignore();
    cout << "Jabatan: ";
    getline(cin, C.jabatan);
    cout << "Departemen: ";
    getline(cin, C.departemen);
    cout << "Status: ";
    getline(cin, C.status);
    cout << "Gaji: ";
    cin >> C.gaji;
    cin.ignore();

    // 06. Melakukan create new elemen berdasarkan data yang diinputkan user
    S = New_Elemen(C);

    // Memanggil salah satu jenis insert (insert First)
    Insert_First(Y, S);
    Show(Y);


    // Meminta user data keempat yang akan dimasukkan ke list
    cout << "Masukkan data keempat:" << endl;
    cout << "Nama: ";
    getline(cin, D.nama);
    cout << "Lama Kerja: ";
    cin >> D.lamaKerja;
    cin.ignore();
    cout << "Jabatan: ";
    getline(cin, D.jabatan);
    cout << "Departemen: ";
    getline(cin, D.departemen);
    cout << "Status: ";
    getline(cin, D.status);
    cout << "Gaji: ";
    cin >> D.gaji;
    cin.ignore();

    // 07. Melakukan create new elemen berdasarkan data yang diinputkan user
    S = New_Elemen(D);

    // 08. Memanggil salah satu jenis insert (insert Last)
    Insert_Last(Y, S);
    Show(Y);


    // Meminta user data kelima yang akan dimasukkan ke list
    cout << "Masukkan data kelima:" << endl;
    cout << "Nama: ";
    getline(cin, E.nama);
    cout << "Lama Kerja: ";
    cin >> E.lamaKerja;
    cin.ignore();
    cout << "Jabatan: ";
    getline(cin, E.jabatan);
    cout << "Departemen: ";
    getline(cin, E.departemen);
    cout << "Status: ";
    getline(cin, E.status);
    cout << "Gaji: ";
    cin >> E.gaji;
    cin.ignore();

    // 09. Melakukan create new elemen berdasarkan data yang diinputkan user
    S = New_Elemen(E);

    // 10. Memanggil salah satu jenis insert (insert after) pada data ke 4
    //cout << "Masukkan posisi data untuk insert after (data ke-): ";
    //cin >> Data_Ke;
    Prev = SearchByNama(Y,D);
    Insert_After(Y, Prev, S);
    Show(Y);



    // Meminta user data keenam yang akan dimasukkan ke list
    cout << "Masukkan data keenam:" << endl;
    cout << "Nama: ";
    getline(cin, F.nama);
    cout << "Lama Kerja: ";
    cin >> F.lamaKerja;
    cin.ignore();
    cout << "Jabatan: ";
    getline(cin, F.jabatan);
    cout << "Departemen: ";
    getline(cin, F.departemen);
    cout << "Status: ";
    getline(cin, F.status);
    cout << "Gaji: ";
    cin >> F.gaji;
    cin.ignore();

    // 11. Melakukan create new elemen berdasarkan data yang diinputkan user
    S = New_Elemen(F);

    // 12. Memanggil salah satu jenis insert (insert after) pada data ke 4
    //cout << "Masukkan posisi data untuk insert after (data ke-4): ";
    Prev = SearchByNama(Y,D);
    Insert_After(Y, Prev, S);



    // Memanggil show (01)
    Show(Y);

    // 13. Melakukan pencarian dan penghapusan data kedua dengan memanfaatkan salah satu jenis delete (delete after)
    address toDelete;
    toDelete = NULL;
    Prev = SearchByNama(Y,B);
    Prev = SearchPrec(Y,Prev);

    Delete_After(Y, Prev, toDelete);

    // 14. Melakukan pencarian dan penghapusan data keenam dengan memanfaatkan salah satu jenis delete (gunakan pengkondisian)
    //address sixth = Prev = SearchByNama(Y,F);
    Prev = SearchByNama(Y,F);
    Prev = SearchPrec(Y,Prev);
    Delete_After(Y, Prev, toDelete);
    //if (sixth != nullptr) {
     //   Delete_First(Y, toDelete);
    //}

    // 15. Melakukan pengurutan elemen pada list berdasarkan sub data yang didefinisikan (nama)
    SortByDepartemen(Y);

    // Menampilkan hasil akhir setelah pengurutan
    Show(Y);

    return 0;
}
