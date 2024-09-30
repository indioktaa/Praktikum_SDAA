#include <iostream>
#include <string>
using namespace std;

struct eventmusik {
    string namaevent;
    string tanggal;
    string lokasi;
    int jumlahpeserta;
    eventmusik *next;
};

void addFirst(eventmusik *&head){
    eventmusik *newNode = new eventmusik;
    cout << "Masukkan nama event: " << endl;
    cin >> newNode->namaevent;
    cout << "Masukkan tanggal event: " << endl;
    cin >> newNode->tanggal;
    cout << "Masukkan lokasi event: " << endl;
    cin >> newNode->lokasi;
    cout << "Masukkan jumlah peserta: " << endl;
    cin >> newNode->jumlahpeserta;

    if (head == nullptr){
        newNode->next = nullptr;
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void addLast(eventmusik *&head){
    eventmusik *newNode = new eventmusik;
    cout << "Masukkan nama event: ";
    cin >> newNode->namaevent;
    cout << "Masukkan tanggal event: ";
    cin >> newNode->tanggal;
    cout << "Masukkan lokasi event: ";
    cin >> newNode->lokasi;
    cout << "Masukan Jumlah Peserta: ";
    cin >> newNode->jumlahpeserta;

    if(head == nullptr){
        head = newNode;
        return;
    }

    eventmusik *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    newNode->next = nullptr;
    temp->next = newNode;
}

void tampilkan(eventmusik *head){
    eventmusik *temp = head;
    int hitung = 1;

    if(temp == nullptr){
        cout << "Tidak ada data" << endl;
        return;
    }

    while (temp != nullptr){
        cout << "Event " << hitung << endl;
        cout << "Nama Event: " << temp->namaevent << endl;
        cout << "Tanggal Event: " << temp->tanggal << endl;
        cout << "Lokasi Event: " << temp->lokasi << endl;
        cout << "Jumlah Peserta: " << temp->jumlahpeserta << endl;
        cout << endl;

        hitung +=1;
        temp = temp->next;
    }

    hitung = 0;
}

void updateevent(eventmusik *&head){
    int updateevent;
    string namaevent;

    tampilkan(head);

    eventmusik *temp = head;

    cout << "Masukan nama event: "; cin >> namaevent;
    cout << endl;

    while(temp->namaevent != namaevent){
        temp = temp->next;
    }

    cout << "Nama ditemukan" << endl;
    cout << "Masukan nama: "; cin >> temp->namaevent;
    cout << "Masukan tanggal event: "; cin >> temp->tanggal;
    cout << "Masukan lokasi event: "; cin >> temp->lokasi;
    cout << "Masukan jumlah peserta event: "; cin >> temp->jumlahpeserta;

}

void deleteFirst(eventmusik *&head){

    if (head == nullptr){
        cout << "Tidak ada yang bisa di hapus." <<endl;
        return;
    }
    eventmusik *temp = head;
    head = head->next;
    delete temp;
    cout << "Event berhasil di hapus." << endl;
}


void deletelast(eventmusik *&head){

    if (head == nullptr){
        cout << "Tidak ada yang bisa di hapus." <<endl;
        return;
    }

    eventmusik *temp = head;
    while (temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    cout << "Event berhasil di hapus." << endl;

}

int main(){
    int pilih;
    eventmusik *head = nullptr;

    while (true){
        cout << "1. Tambah Event" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Ubah Event" << endl;
        cout << "5. Hapus Depan" << endl;
        cout << "6. Hapus Belakang" << endl;
        cout << "7. Keluar dari program" << endl;
        cout << "Pilih: "; cin >> pilih;

        switch (pilih){
            case 1:
            addFirst(head);
            break;

            case 2:
            addLast(head);
            break;

            case 3:
            tampilkan(head);
            break;

            case 4:
            updateevent(head);
            break;

            case 5:
            deleteFirst(head);
            break;

            case 6:
            deletelast(head);
            break;

            case 7:
            cout << "Keluar dari program." << endl;
                break;

            default:
            cout << "Pilihan tidak valid." <<endl;
        }

        if (pilih == 7){
            break;
        }
    }

    return 0;
}