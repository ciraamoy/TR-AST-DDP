#include <stdio.h>
#include <stdlib.h>

/* ================= UTILITAS ================= */
void bersihLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void tekanEnter() {
    int c;
    printf("\nTekan Enter untuk kembali...");
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

/* ================= POLA ================= */

/* 1. Segitiga siku-siku */
void segitigaSiku(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }
}

/* 2. Segitiga siku-siku terbalik */
void segitigaTerbalik(int n) {
    int i, j;
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }
}

/* 3. Piramida */
void piramida(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) printf(" ");
        for (j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
}

/* 4. Belah ketupat */
void belahKetupat(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) printf(" ");
        for (j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) printf(" ");
        for (j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
}

/* 5. Segitiga angka */
void segitigaAngka(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) printf("%d ", j);
        printf("\n");
    }
}

/* 6. Persegi berongga */
void persegiBerongga(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

/* ================= MENU RUMAH POLA ================= */
void rumahPola() {
    int pilih, n;

    do {
        bersihLayar();
        printf("====================================\n");
        printf("            RUMAH POLA              \n");
        printf("====================================\n");
        printf("1. Segitiga Siku-siku\n");
        printf("2. Segitiga Siku-siku Terbalik\n");
        printf("3. Piramida\n");
        printf("4. Belah Ketupat\n");
        printf("5. Segitiga Angka\n");
        printf("6. Persegi Berongga\n");
        printf("0. Keluar\n");
        printf("====================================\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);

        if (pilih >= 1 && pilih <= 6) {
            printf("Masukkan tinggi/ukuran pola : ");
            scanf("%d", &n);
            if (n < 1) {
                printf("Ukuran harus lebih dari 0!\n");
                tekanEnter();
                continue;
            }
            printf("\n");
            switch (pilih) {
                case 1: segitigaSiku(n);     break;
                case 2: segitigaTerbalik(n); break;
                case 3: piramida(n);         break;
                case 4: belahKetupat(n);     break;
                case 5: segitigaAngka(n);    break;
                case 6: persegiBerongga(n);  break;
            }
            tekanEnter();
        } else if (pilih != 0) {
            printf("Pilihan tidak valid!\n");
            tekanEnter();
        }
    } while (pilih != 0);
}

int main() {
    rumahPola();
    return 0;
}

