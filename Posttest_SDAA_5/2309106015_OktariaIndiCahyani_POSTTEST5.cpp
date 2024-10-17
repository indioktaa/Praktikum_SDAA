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

void updateevent(node *head) {
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

node* merge(node* left, node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->event.jumlahpeserta < right->event.jumlahpeserta) {
        left->next = merge(left->next, right);
        left->next->prev = left;
        left->prev = nullptr;
        return left;
    } else {
        right->next = merge(left, right->next);
        right->next->prev = right;
        right->prev = nullptr;
        return right;
    }
}

node* mergesort(node* head) {
    if (!head || !head->next) {
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* secondHalf = slow->next;
    slow->next = nullptr;

    node* left = mergesort(head);
    node* right = mergesort(secondHalf);

    return merge(left, right);
}

node* partition(node* low, node* high) {
    int pivot = high->event.jumlahpeserta;
    node* i = low->prev;

    for (node* j = low; j != high; j = j->next) {
        if (j->event.jumlahpeserta > pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i->event, j->event);
        }
    }

    i = (i == nullptr) ? low : i->next;
    swap(i->event, high->event);
    return i;
}

void quicksort(node* low, node* high) {
    if (high != nullptr && low != high && low != high->next) {
        node* p = partition(low, high);
        quicksort(low, p->prev);
        quicksort(p->next, high);
    }
}

void sortascending() {
    if (!kosong()) {
        head = mergesort(head);
        cout << "Event diurutkan secara ascending berdasarkan jumlah peserta." << endl;
    } else {
        cout << "Tidak ada event untuk diurutkan." << endl;
    }
}

void sortdescending() {
    if (!kosong()) {
        quicksort(head, tail);
        cout << "Event diurutkan secara descending berdasarkan jumlah peserta." << endl;
    } else {
        cout << "Tidak ada event untuk diurutkan." << endl;
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
        cout << "7. Urutkan Event Ascending (Merge Sort)" << endl;
        cout << "8. Urutkan Event Descending (Quick Sort)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: push(head); break;
            case 2: pop(head); break;
            case 3: enqueue(head, tail); break;
            case 4: dequeue(head, tail); break;
            case 5: tampilkan(head); break;
            case 6: updateevent(head); break;
            case 7: sortascending(); break;
            case 8: sortdescending(); break;
            case 0: cout << "Keluar dari program." << endl; 
            break;
            default: cout << "Pilihan tidak valid." << endl; 
            break;
        }
    } while (choice != 0);

    return 0;
}
