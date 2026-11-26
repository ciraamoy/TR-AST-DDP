#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T "\t\t\t\t\t"   /* T = jarak tab di kiri supaya tampilan menjorok seperti contoh */

char judul[100][50];     /* tempat menyimpan judul, maksimal 100 buku */
char penulis[100][50];   /* tempat menyimpan penulis */
int jumlahBuku = 0;      /* jumlah buku yang sudah tersimpan */

/* Membersihkan layar, jadi tampilan terasa seperti pindah halaman */
void bersihLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* Membuang sisa input (misalnya Enter) yang masih tertinggal setelah scanf */
void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/* Menunggu user menekan Enter supaya hasilnya sempat dibaca sebelum layar dibersihkan */
void tungguEnter() {
    printf("\n" T "Tekan Enter untuk kembali ke menu...");
    bersihkanBuffer();
    getchar();
}

/* Mencari buku berdasarkan judul.
   Hasilnya: nomor index buku, atau -1 kalau tidak ketemu */
int cariIndex(char cari[]) {
    int i;
    for (i = 0; i < jumlahBuku; i++) {
        if (strcmp(judul[i], cari) == 0) {   /* strcmp = 0 artinya teksnya sama */
            return i;
        }
    }
    return -1;
}

void tambahBuku() {
    int n, i;

    printf(T "Tambah Buku Baru\n");
    printf(T "-----------------\n");
    printf(T "Masukkan jumlah buku: ");
    if (scanf("%d", &n) != 1) {
        n = 0;
    }

    if (n <= 0) {
        printf(T "Input tidak valid! Masukkan angka positif.\n");
    } else if (jumlahBuku + n > 100) {
        printf(T "Jumlah buku melebihi batas!\n");
    } else {
        for (i = 0; i < n; i++) {
            printf(T "Judul buku ke-%d: ", jumlahBuku + 1);
            scanf("%s", judul[jumlahBuku]);
            printf(T "Penulis buku '%s': ", judul[jumlahBuku]);
            scanf("%s", penulis[jumlahBuku]);
            jumlahBuku++;
        }
        printf(T "Buku berhasil ditambahkan!\n");
    }
}

void cariBuku() {
    char cari[50];
    int i;

    printf(T "Cari Buku\n");
    printf(T "---------\n");
    printf(T "Masukkan judul buku: ");
    scanf("%s", cari);

    i = cariIndex(cari);
    if (i == -1) {
        printf(T "Buku '%s' tidak ditemukan!\n", cari);
    } else {
        printf(T "Judul: %s\n", judul[i]);
        printf(T "Penulis: %s\n", penulis[i]);
    }
}

void ubahPenulis() {
    char cari[50];
    int i;

    printf(T "Ubah Data Penulis\n");
    printf(T "-----------------\n");
    printf(T "Masukkan judul buku yang ingin diubah: ");
    scanf("%s", cari);

    i = cariIndex(cari);
    if (i == -1) {
        printf(T "Buku '%s' tidak ditemukan!\n", cari);
    } else {
        printf(T "Penulis saat ini: %s\n", penulis[i]);
        printf(T "Masukkan penulis baru: ");
        scanf("%s", penulis[i]);
        printf(T "Penulis berhasil diperbarui!\n");
    }
}

void hapusBuku() {
    char cari[50];
    int i, j;

    printf(T "Hapus Buku\n");
    printf(T "-----------\n");
    printf(T "Masukkan judul buku yang ingin dihapus: ");
    scanf("%s", cari);

    i = cariIndex(cari);
    if (i == -1) {
        printf(T "Buku '%s' tidak ditemukan!\n", cari);
    } else {
        /* geser data setelahnya ke depan untuk menimpa buku yang dihapus */
        for (j = i; j < jumlahBuku - 1; j++) {
            strcpy(judul[j], judul[j + 1]);
            strcpy(penulis[j], penulis[j + 1]);
        }
        jumlahBuku--;
        printf(T "Buku '%s' berhasil dihapus!\n", cari);
    }
}

void menuPerpustakaan() {
    int pilihan;

    do {
        /* Halaman menu */
        bersihLayar();
        printf("\n");
        printf(T "=== PERPUSTAKAAN MINI ===\n");
        printf(T "1. Tambah Buku\n");
        printf(T "2. Cari Buku\n");
        printf(T "3. Ubah Penulis\n");
        printf(T "4. Hapus Buku\n");
        printf(T "5. Keluar\n");
        printf(T "Pilih menu: ");
        if (scanf("%d", &pilihan) != 1) {
            pilihan = 0;          /* kalau yang diketik bukan angka */
            bersihkanBuffer();
        }

        /* Halaman hasil pilihan (layar dibersihkan dulu) */
        bersihLayar();
        printf("\n");

        switch (pilihan) {
            case 1: tambahBuku(); tungguEnter(); break;
            case 2: cariBuku(); tungguEnter(); break;
            case 3: ubahPenulis(); tungguEnter(); break;
            case 4: hapusBuku(); tungguEnter(); break;
            case 5:
                printf(T "Terima kasih telah menggunakan program!\n");
                tungguEnter();
                break;
            default:
                printf(T "Pilihan tidak valid!\n");
                tungguEnter();
        }
    } while (pilihan != 5);
}

/* main ini cuma untuk tes. Hapus saat digabung ke program utama */
int main() {
    menuPerpustakaan();
    return 0;
}