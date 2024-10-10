#include <iostream>
#include <string>
using namespace std;

struct eventmusik {
    string namaevent;
    string tanggal;
    string lokasi;
    int jumlahpeserta;
};

struct node {
    eventmusik event;
    node *next;
    node *prev;
};

node *head = nullptr;
node *tail = nullptr;

bool kosong() {
    return head == nullptr;
}

void push(node *&head) {
    eventmusik newEvent;
    cout << "Masukkan nama event: ";
    cin >> newEvent.namaevent;
    cout << "Masukkan tanggal event: ";
    cin >> newEvent.tanggal;
    cout << "Masukkan lokasi event: ";
    cin >> newEvent.lokasi;
    cout << "Masukkan jumlah peserta: ";
    cin >> newEvent.jumlahpeserta;

    node *newNode = new node;
    newNode->event = newEvent;
    newNode->next = head;
    newNode->prev = nullptr;

    if (kosong()) {
        tail = newNode;
    } else {
        head->prev = newNode;
    }
    head = newNode;

    cout << "Event berhasil ditambahkan" << endl;
}

void pop(node *&head) {
    if (kosong()) {
        cout << "Stack kosong" << endl;
        return;
    }

    node *temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; 
    }
    delete temp;

    cout << "Event berhasil dihapus" << endl;
}

void enqueue(node *&head, node *&tail) {
    eventmusik newEvent;
    cout << "Masukkan nama event: ";
    cin >> newEvent.namaevent;
    cout << "Masukkan tanggal event: ";
    cin >> newEvent.tanggal;
    cout << "Masukkan lokasi event: ";
    cin >> newEvent.lokasi;
    cout << "Masukkan jumlah peserta: ";
    cin >> newEvent.jumlahpeserta;

    node *newNode = new node;
    newNode->event = newEvent;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (kosong()) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;

    cout << "Event berhasil ditambahkan" << endl;
}

void dequeue(node *&head, node *&tail) {
    if (kosong()) {
        cout << "Queue kosong" << endl;
        return;
    }

    node *temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;

    cout << "Event berhasil dihapus" << endl;
}

void tampilkan(node *head) {
    if (kosong()) {
        cout << "Tidak ada event" << endl;
        return;
    } else {
        node *temp = head;
        int count = 1;

        while (temp != nullptr) {
            cout << "Event ke-" << count << endl;
            cout << "Nama Event: " << temp->event.namaevent << endl;
            cout << "Tanggal Event: " << temp->event.tanggal << endl;
            cout << "Lokasi: " << temp->event.lokasi << endl;
            cout << "Jumlah Peserta: " << temp->event.jumlahpeserta << endl;
            cout << "----------------------------------------" << endl;
            temp = temp->next;
            count++;
        }
    }
}

void updateEvent(node *head) {
    if (kosong()) {
        cout << "Tidak ada event" << endl;
        return;
    }

    string namaevent;
    cout << "Masukkan nama event yang ingin di-update: ";
    cin >> namaevent;

    node *temp = head;
    while (temp != nullptr && temp->event.namaevent != namaevent) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        cout << "Event ditemukan. Masukkan data baru untuk event ini" << endl;
        cout << "Nama Event: ";
        cin >> temp->event.namaevent;
        cout << "Tanggal Event: ";
        cin >> temp->event.tanggal;
        cout << "Lokasi Event: ";
        cin >> temp->event.lokasi;
        cout << "Jumlah peserta: ";
        cin >> temp->event.jumlahpeserta;

        cout << "Event berhasil di-update." << endl;
    } else {
        cout << "Event tidak ditemukan." << endl;
    }
}

int main() {
    int choice;
    do {
        
        cout << "Menu:" << endl;
        cout << "1. Tambah Event (Push)" << endl;
        cout << "2. Hapus Event (Pop)" << endl;
        cout << "3. Tambah Event (Enqueue)" << endl;
        cout << "4. Hapus Event (Dequeue)" << endl;
        cout << "5. Tampilkan Semua Event" << endl;
        cout << "6. Update Event" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: push(head); break;
            case 2: pop(head); break;
            case 3: enqueue(head, tail); break;
            case 4: dequeue(head, tail); break;
            case 5: tampilkan(head); break;
            case 6: updateEvent(head); break;
            case 0: cout << "Keluar dari program." << endl; 
            break;
            default: cout << "Pilihan tidak valid." << endl; 
            break;
        }
    } while (choice != 0);

    return 0;
}
