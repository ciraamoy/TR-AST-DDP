#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 100

// struct buat nyimpan data nasabah
struct Nasabah {
    char nama[50];
    char pin[20];
    long saldo;
    time_t waktuBuat;
    time_t waktuUpdate;
};

struct Nasabah data[MAX];   // tempat nyimpan semua nasabah
int jumlah = 0;             // jumlah nasabah sekarang

// fungsi buat nunggu user tekan enter
void tunggu() {
    while (getchar() != '\n');   // buang sisa enter dari scanf
    getchar();                   // nunggu user tekan enter
}

// fungsi cek apakah string isinya angka semua
int cekAngka(char s[]) {
    int i;
    if (strlen(s) == 0) {
        return 0;
    }
    for (i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

// fungsi buat ngubah waktu jadi format dd/mm/yyyy hh:mm
void formatWaktu(time_t t, char hasil[]) {
    struct tm *w = localtime(&t);
    strftime(hasil, 30, "%d/%m/%Y %H:%M", w);
}

// fungsi buat cari nasabah, kalau ketemu return index, kalau nggak return -1
int cariNasabah(char nama[], char pin[]) {
    int i;
    for (i = 0; i < jumlah; i++) {
        if (strcmp(data[i].nama, nama) == 0 && strcmp(data[i].pin, pin) == 0) {
            return i;
        }
    }
    return -1;
}

// 1. buka rekening
void bukaRekening() {
    char nama[50], pin[20], saldoStr[30];
    long saldo;

    system("cls");
    system("color 5F");
    printf("=== BUKA REKENING BARU ===\n");

    if (jumlah >= MAX) {
        printf("Data nasabah sudah penuh!\n");
        tunggu();
        return;
    }

    printf("Masukkan nama nasabah: ");
    scanf("%s", nama);
    printf("Masukkan PIN (tanpa spasi): ");
    scanf("%s", pin);

    // ulang terus sampai saldo yang dimasukkan valid
    while (1) {
        printf("Masukkan saldo awal: ");
        scanf("%s", saldoStr);
        if (cekAngka(saldoStr) == 1) {
            saldo = atol(saldoStr);
            break;
        } else {
            printf("Input saldo tidak valid! Masukkan angka >= 0.\n");
        }
    }

    strcpy(data[jumlah].nama, nama);
    strcpy(data[jumlah].pin, pin);
    data[jumlah].saldo = saldo;
    data[jumlah].waktuBuat = time(NULL);
    data[jumlah].waktuUpdate = time(NULL);
    jumlah++;

    printf("\nRekening atas nama '%s' berhasil dibuat!\n", nama);
    printf("\nTekan ENTER untuk kembali ke menu...");
    tunggu();
}

// 2. lihat semua nasabah
void lihatNasabah() {
    int i;
    char buat[30], update[30];

    system("cls");
    system("color 9F");
    printf("=== DAFTAR NASABAH (ADMIN) ===\n");
    printf("+----+------------------------+------------+-------------------+-------------------+\n");
    printf("| No | Nama Nasabah           | Saldo      | Waktu Buat        | Terakhir Update   |\n");
    printf("+----+------------------------+------------+-------------------+-------------------+\n");

    for (i = 0; i < jumlah; i++) {
        formatWaktu(data[i].waktuBuat, buat);
        formatWaktu(data[i].waktuUpdate, update);
        printf("| %-2d | %-22s | Rp%-8ld | %-17s | %-17s |\n",
               i + 1, data[i].nama, data[i].saldo, buat, update);
    }

    printf("+----+------------------------+------------+-------------------+-------------------+\n");
    printf("\nTekan ENTER untuk kembali ke menu...");
    tunggu();
}

// menu setelah login (setor, tarik, logout)
void menuNasabah(int idx) {
    int pilih;
    char jumlahStr[30];
    long nominal;
    char *waktu;

    while (1) {
        system("cls");
        system("color 1F");
        waktu = ctime(&data[idx].waktuUpdate);
        waktu[strlen(waktu) - 1] = '\0';   // hapus enter di akhir ctime

        printf("=== MENU NASABAH ===\n");
        printf("Nama: %s\n", data[idx].nama);
        printf("Saldo: Rp%ld\n", data[idx].saldo);
        printf("Terakhir update: %s\n", waktu);
        printf("\n1. Setor Tunai\n");
        printf("2. Tarik Tunai\n");
        printf("3. Logout\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        if (pilih == 1) {
            // setor tunai
            system("cls");
            system("color 2F");
            printf("=== MENU NASABAH ===\n");
            printf("Nama: %s\n", data[idx].nama);
            printf("Saldo: Rp%ld\n\n", data[idx].saldo);

            printf("Masukkan jumlah setor: ");
            scanf("%s", jumlahStr);

            if (cekAngka(jumlahStr) == 0 || atol(jumlahStr) <= 0) {
                printf("Input tidak valid! Masukkan angka > 0.\n");
            } else {
                nominal = atol(jumlahStr);
                data[idx].saldo = data[idx].saldo + nominal;
                data[idx].waktuUpdate = time(NULL);
                waktu = ctime(&data[idx].waktuUpdate);
                waktu[strlen(waktu) - 1] = '\0';
                printf("Setor berhasil! Saldo sekarang: Rp%ld\n", data[idx].saldo);
                printf("Waktu transaksi: %s\n", waktu);
            }
            printf("\nTekan ENTER untuk kembali...");
            tunggu();

        } else if (pilih == 2) {
            // tarik tunai
            system("cls");
            system("color 4F");
            printf("=== MENU NASABAH ===\n");
            printf("Nama: %s\n", data[idx].nama);
            printf("Saldo: Rp%ld\n\n", data[idx].saldo);

            printf("Masukkan jumlah tarik: ");
            scanf("%s", jumlahStr);

            if (cekAngka(jumlahStr) == 0 || atol(jumlahStr) <= 0) {
                printf("Input tidak valid! Masukkan angka > 0.\n");
            } else {
                nominal = atol(jumlahStr);
                if (nominal > data[idx].saldo) {
                    printf("Saldo tidak cukup!\n");
                } else {
                    data[idx].saldo = data[idx].saldo - nominal;
                    data[idx].waktuUpdate = time(NULL);
                    waktu = ctime(&data[idx].waktuUpdate);
                    waktu[strlen(waktu) - 1] = '\0';
                    printf("Tarik berhasil! Saldo sekarang: Rp%ld\n", data[idx].saldo);
                    printf("Waktu transaksi: %s\n", waktu);
                }
            }
            printf("\nTekan ENTER untuk kembali...");
            tunggu();

        } else if (pilih == 3) {
            break;   // logout, balik ke menu utama
        } else {
            printf("\nPilihan tidak ada!\n");
            printf("Tekan ENTER untuk kembali...");
            tunggu();
        }
    }
}

// 3. login nasabah
void loginNasabah() {
    char nama[50], pin[20];
    int idx;

    system("cls");
    system("color 6F");
    printf("=== LOGIN NASABAH ===\n");
    printf("Masukkan nama: ");
    scanf("%s", nama);
    printf("Masukkan PIN: ");
    scanf("%s", pin);

    idx = cariNasabah(nama, pin);

    if (idx == -1) {
        printf("\nNama atau PIN salah!\n");
        printf("Tekan ENTER untuk kembali...");
        tunggu();
    } else {
        printf("\nLogin berhasil! Selamat datang, %s.\n", data[idx].nama);
        printf("Tekan ENTER untuk lanjut...");
        tunggu();
        menuNasabah(idx);
    }
}

// 4. hapus rekening
void hapusRekening() {
    char nama[50], pin[20];
    int idx, i;

    system("cls");
    system("color 4F");
    printf("=== HAPUS REKENING ===\n");
    printf("Masukkan nama: ");
    scanf("%s", nama);
    printf("Masukkan PIN: ");
    scanf("%s", pin);

    idx = cariNasabah(nama, pin);

    if (idx == -1) {
        printf("\nNama atau PIN salah! Rekening tidak ditemukan.\n");
    } else {
        // geser data ke kiri nimpa data yang dihapus
        for (i = idx; i < jumlah - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlah--;
        printf("\nRekening '%s' berhasil dihapus!\n", nama);
    }

    printf("\nTekan ENTER untuk kembali...");
    tunggu();
}

int main() {
    int pilih;

    while (1) {
        system("cls");
        system("color 1F");
        printf("=== ATM SEDERHANA ===\n");
        printf("1. Buka Rekening\n");
        printf("2. Lihat Semua Nasabah\n");
        printf("3. Login Nasabah\n");
        printf("4. Hapus Rekening\n");
        printf("5. Keluar\n");
        printf("\nPilih menu: ");
        scanf("%d", &pilih);

        if (pilih == 1) {
            bukaRekening();
        } else if (pilih == 2) {
            lihatNasabah();
        } else if (pilih == 3) {
            loginNasabah();
        } else if (pilih == 4) {
            hapusRekening();
        } else if (pilih == 5) {
            printf("\nTerima kasih sudah menggunakan ATM!\n");
            break;
        } else {
            printf("\nPilihan tidak ada!\n");
            printf("Tekan ENTER untuk kembali...");
            tunggu();
        }
    }

    return 0;
}