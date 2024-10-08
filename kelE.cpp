#include "kelE.h"

// Membuat List baru
void Create_List(List &L) {
    L.first = nullptr;
}

// Membuat elemen baru dengan data yang diberikan
address New_Elemen(infotype data) {
    address p = new elmList;
    p->info = data;
    p->next = nullptr;
    return p;
}

// Memasukkan elemen baru di awal list
void Insert_First(List &L, address p) {
    if (L.first == nullptr){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

// Memasukkan elemen baru di akhir list
void Insert_Last(List &L, address p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

// Memasukkan elemen baru setelah elemen tertentu
void Insert_After(List &L, address prev, address p) {
    if (L.first == NULL){
        L.first = p;
    }else{
        p->next = prev->next;
        prev->next = p;
    }
}

// Menghapus elemen pertama di list
void Delete_First(List &L, address &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        p->next = nullptr;
    }
}

// Menghapus elemen terakhir di list
void Delete_Last(List &L, address &p) {
    address first;
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first->next == nullptr){
        p = L.first;
        first = nullptr;
    } else {
        address q = L.first;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

// Menghapus elemen setelah elemen tertentu
void Delete_After(List &L, address prec, address &p) {
    if ((L.first == NULL)||(prec->next==NULL)){
        p = NULL;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}

// Menampilkan seluruh elemen di dalam list
void Show(List L) {
    address p = L.first;
    int i = 1;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    while (p != nullptr) {
        cout << "Data ke-" << i << ":" << endl;
        cout << "Nama: " << p->info.nama << endl;
        cout << "Lama Kerja: " << p->info.lamaKerja << " tahun" << endl;
        cout << "Jabatan: " << p->info.jabatan << endl;
        cout << "Departemen: " << p->info.departemen << endl;
        cout << "Status: " << p->info.status << endl;
        cout << "Gaji: " << p->info.gaji << endl;
        cout << "-----------------------------" << endl;
        p = p->next;
        i++;
    }
    if (L.first == nullptr) {
        cout << "List kosong." << endl;
    }
}



// Mengurutkan elemen berdasarkan Nama (Selection Sort)
void SortByNama(List &L) {
    if (L.first != nullptr) {
        address p = L.first;
        while (p != nullptr) {
            address mins = p;
            address q = p->next;

            while (q != nullptr) {
                if (q->info.nama < mins->info.nama) {
                    mins = q;
                }
                q = q->next;
            }
            if (mins != p) {
                infotype temp = p->info;
                p->info = mins->info;
                mins->info = temp;
            }
            p = p->next;
        }
    }
}


// Mengurutkan elemen berdasarkan Lama Kerja (Insertion Sort)
void SortByLamaKerja(List &L) {
   if (L.first != nullptr) {
        address p = L.first->next;
        L.first->next = nullptr;
        while (p != nullptr) {
            address q = p->next;
            if (L.first->info.lamaKerja > p->info.lamaKerja) {
                p->next = L.first;
                L.first = p;
            } else {
                address r = L.first;
                while (r->next != nullptr && r->next->info.lamaKerja <= p->info.lamaKerja) {
                    r = r->next;
                }
                p->next = r->next;
                r->next = p;
            }
            p = q;
        }
    }
}

// Mencari elemen berdasarkan Status
address SearchByStatus(List L, infotype data) {
    address p = L.first;

    while (p != nullptr) {
        if (p->info.status == data.status) {
            return p;
        }
        p = p->next;
    }
    return nullptr
}

// Mengurutkan elemen berdasarkan Gaji (Selection Sort)
void SortByGaji(List &L) {
    address p, q, mins;
    if (L.first != nullptr) {
        infotype temp;
        p = L.first;
        while (p != nullptr) {
            mins = p;
            q = p->next;
            while (q != nullptr) {
                if (q->info.gaji < mins->info.gaji) {
                    mins = q;
                }
                q = q->next;
            }
            temp = p->info;
            p->info = mins->info;
            mins->info = temp;

            p = p->next;
        }
    }
}

// Mencari elemen berdasarkan Departemen
address SearchByDepartemen(List L, infotype data) {
    address p = L.first;
    while (p != nullptr) {
        if (p->info.departemen == data.departemen) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// Mencari elemen berdasarkan Jabatan
address SearchByJabatan(List L, infotype data) {
    address p = L.first;
    while (p != nullptr) {
        if (p->info.jabatan == data.jabatan) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// Mencari elemen berdasarkan Lama Kerja (Binary Search)
address SearchByLamaKerja(List L, infotype data) {
    address start = L.first;
    address ends = nullptr;

    while (start != ends) {
        address slow = start;
        address fast = start;

        while (fast != ends && fast->next != ends) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (slow->info.lamaKerja == data.lamaKerja) {
            return slow;
        } else if (slow->info.lamaKerja < data.lamaKerja) {
            start = slow->next;
        } else {
            ends = slow;
        }
    }
    return nullptr;
}


// Mengurutkan elemen berdasarkan jabatan (Selection Sort)
void SortByJabatan(List &L) {
    address next,prev, sl, temp;
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    sl = nullptr;
    prev = L.first;

    while (prev != nullptr) {
        next = prev->next;
        if (sl == nullptr || sl->info.jabatan > prev->info.jabatan) {
            prev->next = sl;
            sl = prev;
        } else {
            temp = sl;
            while (temp->next != nullptr && temp->next->info.jabatan < prev->info.jabatan) {
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next = prev;
        }
        prev = next;
    }

    L.first = sl;
}

// Mengurutkan elemen berdasarkan departemen (Selection Sort)
void SortByDepartemen(List &L) {
    address p, q, mins;
    if (L.first != nullptr) {
        infotype temp;
        p = L.first;
        while (p != nullptr) {
            mins = p;
            q = p->next;
            while (q != nullptr) {
                if (q->info.departemen < mins->info.departemen) {
                    mins = q;
                }
                q = q->next;
            }
            temp = p->info;
            p->info = mins->info;
            mins->info = temp;

            p = p->next;
        }
    }
}

//Mengurutkan elemen berdasarkan status (selection)
void SortByStatus(List &L) {
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    address prev = L.first;

    while (prev != nullptr) {
        address mins = prev;
        address temp = prev->next;

        while (temp != nullptr) {
            if (temp->info.status < mins->info.status) {
                mins = temp;
            }
            temp = temp->next;
        }

        if (mins != prev) {
            infotype tempInfo = prev->info;
            prev->info = mins->info;
            mins->info = tempInfo;
        }

        prev = prev->next;
    }
}

//Mencari elemen berdasar nama
address SearchByNama(List L, infotype data) {
    address p = L.first;

    while (p != nullptr) {
        if (p->info.nama == data.nama) {
            return p;
        }
        p = p->next;
    }

    return nullptr;
}


// Mencari elemen berdasarkan Prec
address SearchPrec(List L, address data) {
    address p = L.first;
    while (p->next->info.nama != data->info.nama) {
        p = p->next;
    }
    return p;
}
