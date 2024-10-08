#ifndef KELE_H_INCLUDED
#define KELE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Karyawan {
    string nama;
    int lamaKerja;
    string jabatan;
    string departemen;
    string status;
    float gaji;
};

typedef Karyawan infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Prosedur dan fungsi terkait ADT Single Linked List
void Create_List(List &L);
address New_Elemen(infotype data);
void Insert_First(List &L, address p);
void Insert_Last(List &L, address p);
void Insert_After(List &L, address prev, address p);
void Delete_First(List &L, address &p);
void Delete_Last(List &L, address &p);
void Delete_After(List &L, address prec, address &p);
void Show(List L);
void SortByNama(List &L);
void SortByLamaKerja(List &L);
void SortByJabatan(List &L);
void SortByDepartemen(List &L);
void SortByStatus(List &L);
void SortByGaji(List &L);
address SearchByNama(List L, infotype data);
address SearchByDepartemen(List L, infotype data);
address SearchByJabatan(List L, infotype data);
address SearchByStatus(List L, infotype data);
address SearchByLamaKerja(List L, infotype data);
address SearchPrec(List L, address data);



#endif // KELE_H_INCLUDED
