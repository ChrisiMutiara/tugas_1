#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct kendaraan {
    string plat;     
    string jenis;   
    string merk;     
    string model;    
    string pemilik;  
    int tahun;       
};

void inputData(kendaraan kendaraan[], int &jumlahkend) {
    cout << "\nINPUT DATA KENDARAAN\n";
    cout << "Banyaknya data kendaraan = ";
    cin >> jumlahkend;
    cin.ignore();

    for (int i = 0; i < jumlahkend; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Plat      = "; getline(cin, kendaraan[i].plat);
        cout << "Jenis     = "; getline(cin, kendaraan[i].jenis);
        cout << "Merk      = "; getline(cin, kendaraan[i].merk);
        cout << "Model     = "; getline(cin, kendaraan[i].model);
        cout << "Pemilik   = "; getline(cin, kendaraan[i].pemilik);
        cout << "Tahun     = "; cin >> kendaraan[i].tahun;
        cin.ignore();
    }
    cout << "Data berhasil ditambahkan!\n";
}

void tampilData(kendaraan kendaraan[], int jumlahkend) {
    cout << "\nDATA KENDARAAN\n";
    cout << "------------------------------------------------------------------------------\n";
    cout << "| No |   Plat    |   Jenis   |   Merk    |   Model   |  Pemilik  |  Tahun  |\n";
    cout << "------------------------------------------------------------------------------\n";
    
    for (int i = 0; i < jumlahkend; i++) {
        cout << "| " << setw(2) << i + 1 << " | " 
             << setw(9) << kendaraan[i].plat << " | "
             << setw(9) << kendaraan[i].jenis << " | "
             << setw(9) << kendaraan[i].merk << " | " 
             << setw(9) << kendaraan[i].model << " | "
             << setw(9) << kendaraan[i].pemilik << " | " 
             << setw(7) << kendaraan[i].tahun << " |\n";
    }
    
    cout << "------------------------------------------------------------------------------\n";
}

void bubbleSort(kendaraan kendaraan[], int jumlahkend) {
    cout << "\nData sebelum diurutkan:\n";
    tampilData(kendaraan, jumlahkend);

    for (int i = 0; i < jumlahkend - 1; i++) {
        for (int j = 0; j < jumlahkend - i - 1; j++) {
            if (kendaraan[j].tahun > kendaraan[j + 1].tahun) {
                swap(kendaraan[j], kendaraan[j + 1]);
            }
        }
    }

    cout << "\nData setelah diurutkan:\n";
    tampilData(kendaraan, jumlahkend);
    cout << "Data berhasil diurutkan berdasarkan tahun produksi.\n";
}

void sequentialSearch(kendaraan kendaraan[], int jumlahkend) {
    string cariPemilik;
    cout << "Masukkan Nama Pemilik yang dicari: "; getline(cin, cariPemilik);
    
    cout << "\nHASIL PENCARIAN\n";
    cout << "------------------------------------------------------------------------------\n";
    cout << "| No |   Plat    |   Jenis   |   Merk    |   Model   |  Pemilik  |  Tahun  |\n";
    cout << "------------------------------------------------------------------------------\n";
    
    bool ditemukan = false;
    int count = 0;
    
    for (int i = 0; i < jumlahkend; i++) {
        if (kendaraan[i].pemilik == cariPemilik) {
            count++;
            cout << "| " << setw(2) << count << " | " 
                 << setw(9) << kendaraan[i].plat << " | "
                 << setw(9) << kendaraan[i].jenis << " | "
                 << setw(9) << kendaraan[i].merk << " | " 
                 << setw(9) << kendaraan[i].model << " | "
                 << setw(9) << kendaraan[i].pemilik << " | " 
                 << setw(7) << kendaraan[i].tahun << " |\n";
            ditemukan = true;
        }
    }
    
    cout << "------------------------------------------------------------------------------\n";
    
    if (!ditemukan) {
        cout << "Data dengan pemilik '" << cariPemilik << "' tidak ditemukan.\n";
    } else {
        cout << "Ditemukan " << count << " data kendaraan dengan pemilik '" << cariPemilik << "'.\n";
    }
}

int main() {
    int pilihan, jumlahkend = 0;
    kendaraan kendaraan[100]; 

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Input Data kendaraan\n";
        cout << "2. Tampilkan Seluruh Data kendaraan\n";
        cout << "3. Urutkan Data kendaraan (Bubble Sort)\n";
        cout << "4. Cari Data kendaraan (Sequential Search)\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: inputData(kendaraan, jumlahkend); break;
            case 2: tampilData(kendaraan, jumlahkend); break;
            case 3: bubbleSort(kendaraan, jumlahkend); break;
            case 4: sequentialSearch(kendaraan, jumlahkend); break;
            case 5: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    return 0;
}