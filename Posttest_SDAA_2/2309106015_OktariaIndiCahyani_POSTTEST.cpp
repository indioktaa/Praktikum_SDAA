#include <iostream>
#include <string>
using namespace std;

struct EventMusik {
    string namaEvent;
    string tanggal;
    string lokasi;
    int jumlahPeserta;
};

void tambahEvent(EventMusik *kategori, int &jumlahEvent) {
    cin.ignore(); // Untuk mengabaikan karakter newline dari input sebelumnya
    cout << "Masukkan nama event: ";
    getline(cin, kategori[jumlahEvent].namaEvent); // Menggunakan getline untuk mengizinkan spasi
    cout << "Masukkan tanggal event: ";
    getline(cin, kategori[jumlahEvent].tanggal);
    cout << "Masukkan lokasi event: ";
    getline(cin, kategori[jumlahEvent].lokasi);
    cout << "Masukkan jumlah peserta: ";
    cin >> kategori[jumlahEvent].jumlahPeserta;
    jumlahEvent++;
}

void tampilkanEvent(EventMusik *kategori, int jumlahEvent){
    for (int i = 0; i < jumlahEvent; i++){
        cout << "Event " << i + 1 << ": " << kategori[i].namaEvent << endl;
        cout << "pada " << kategori[i].tanggal << endl;
        cout << "di " << kategori[i].lokasi << endl;
        cout << "dengan jumlah peserta " << kategori[i].jumlahPeserta << endl;
    }
}

void updateEvent(EventMusik *kategori, int jumlahEvent){
    int nomorEvent;
    cout << "Masukkan nomor event yang ingin diupdate: ";
    cin >> nomorEvent;
    if (nomorEvent > 0 && nomorEvent <= jumlahEvent){
        cin.ignore(); // Untuk mengabaikan karakter newline dari input sebelumnya
        cout << "Masukkan nama event baru: ";
        getline(cin, kategori[nomorEvent - 1].namaEvent);
        cout << "Masukkan tanggal event baru: ";
        getline(cin, kategori[nomorEvent - 1].tanggal);
        cout << "Masukkan lokasi event baru: ";
        getline(cin, kategori[nomorEvent - 1].lokasi);
        cout << "Masukkan jumlah peserta baru: ";
        cin >> kategori[nomorEvent - 1].jumlahPeserta;
        cout << "Event berhasil di update. \n";
    } else {
        cout << "Nomor event tidak valid. \n";
    }
}

void hapusEvent(EventMusik *kategori, int &jumlahEvent){
    int nomorEvent;
    cout << "Masukkan nomor event yang ingin dihapus: ";
    cin >> nomorEvent;

    if (nomorEvent > 0 && nomorEvent <= jumlahEvent){
        for (int i = nomorEvent - 1; i < jumlahEvent - 1; i++){
            kategori[i] = kategori[i + 1];
        }
        jumlahEvent--;
        cout << "Event berhasil di hapus.\n";
    } else {
        cout << "Nomor event tidak valid\n";
    }
}

int main(){
    int jumlahEvent = 0;
    EventMusik *kategori = new EventMusik[100];

    int pilihan;
    do {
        cout << "Pilih menu: \n";
        cout << "1. Tambah Event \n";
        cout << "2. Tampilkan Event \n";
        cout << "3. Update Event \n";
        cout << "4. Hapus Event \n";
        cout << "5. Keluar \n";
        cout << "Masukan pilihan anda: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:
                tambahEvent(kategori, jumlahEvent);
                break;
            case 2:
                tampilkanEvent(kategori, jumlahEvent);
                break;
            case 3:
                updateEvent(kategori, jumlahEvent);
                break;
            case 4:
                hapusEvent(kategori, jumlahEvent);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 5);

    delete[] kategori; 
    return 0;
}
