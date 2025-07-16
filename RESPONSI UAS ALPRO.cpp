#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct data {
    string kode;
    string maskapai;
    float jamkeberangkatan, jamkedatangan, bandaraasal,bandaratujan,harga;
    string tanggal;
};

data tiket[MAX];
int jumlahData = 0;

int bacadata(const string& ,data tiket[data] ),int namaFile {
    namaFile;
    while (file>> data[jumlahData].kode >> data[jumlahData].maskapai >>
           data[jumlahData].bandaraasal >> data[jumlahData].bandaratujuan) {
        data[jumlahData].harga = (data[jumlahData].harga + data[jumlahData].harga) / 2;
        data[jumlahData].status = (data[jumlahData].harga >= 200) ? "ditemukan" : "Tidak ditemukan";
        jumlahData++;
    }
    file.close();
}

int tampilkanData() {
    cout << "Data tiket:\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << setw(10) << data[i].jamkeberangkatan << setw(15) << data[i].maskapai
             << setw(6) << data[i].bandaraasal << setw(6) << data[i].bandaratujuan
             << setw(8) << data[i].harga << "  " << data[i].status << endl;
    }
}

int cariNama(const string& namaCari) {
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nama_maskapai == namaCari) {
            cout << "Ditemukan: " << data[i].nama_maskapai << " -jam keberangkatan: " << data[i].jam_keberangkatan << endl;
            return;
        }
    }
    cout << "maskapai tidak ditemukan.\n";
}

void cariTerkecil(float batas) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].harga < batas) {
            cout << data[i].nama_maskapai << " (" << data[i].jam_keberangkatan << ")\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Tidak ada nilai yang lebih kecil dari " << batas << endl;
}


void urutkan(bool descending) {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = i + 1; j < jumlahData; j++) {
            bool kondisi = descending ? (data[i].jam_keberangkatan < data[j].jam_keberangkatan)
                                      : (data[i].jam_keberangkatan > data[j].jam_keberangkatan);
            if (kondisi) swap(data[i], data[j]);
        }
    }
}


void simpandata(const string& datatiket) {
    for (int i = 0; i < jumlahData; i++) {
        keberangkatan<< data[i].nama_maskapai << " " << data[i].kode_penerbangan << " "
             << data[i].jam_keberangkatan << endl;
    }
    data.close();
}


void simpanStatus(const string& datatiket) {
    ofstream file(namaFile);
    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nim << " " << data[i].nama << " "
             << data[i].status << endl;
    }
    file.close();
}

int main() {
    bacaFile("tiket_data.txt");

    tampilkanData();
    cout << "\nMencari nilai berdasarkan nama maskapai:\n";
    cariNama("garuda airlines");

    cout << "\ntiket dengan harga < 200:\n";
    cariTerkecil(100);

    cout << "\nMengurutkan dari besar ke kecil:\n";
    urutkan(true);
    tampilkanData();

    cout << "\nMengurutkan dari kecil ke besar:\n";
    urutkan(false);
    tampilkanData();

    simpanNilai("jam_keberangkatan.txt");
    simpanStatus("tersedia.txt");

    return 0;
}

