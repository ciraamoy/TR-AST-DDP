#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int kamu, komputer;
    char mainLagi;

    srand(time(NULL));

    do {
        printf("\n=== BATU GUNTING KERTAS ===\n");
        printf("1. Batu\n");
        printf("2. Gunting\n");
        printf("3. Kertas\n");
        printf("Pilihan kamu : ");
        scanf("%d", &kamu);

        komputer = rand() % 3 + 1;

        printf("Kamu     : ");
        if (kamu == 1) {
            printf("Batu\n");
        } else if (kamu == 2) {
            printf("Gunting\n");
        } else if (kamu == 3) {
            printf("Kertas\n");
        } else {
            printf("Tidak valid\n");
        }

        printf("Komputer : ");
        if (komputer == 1) {
            printf("Batu\n");
        } else if (komputer == 2) {
            printf("Gunting\n");
        } else {
            printf("Kertas\n");
        }

        if (kamu < 1 || kamu > 3) {
            printf("Pilihan tidak valid!\n");
        } else if (kamu == komputer) {
            printf("Hasil : SERI!\n");
        } else if ((kamu == 1 && komputer == 2) ||
                   (kamu == 2 && komputer == 3) ||
                   (kamu == 3 && komputer == 1)) {
            printf("Hasil : KAMU MENANG!\n");
        } else {
            printf("Hasil : KOMPUTER MENANG!\n");
        }

        printf("Main lagi? (y/n): ");
        scanf(" %c", &mainLagi);
    } while (mainLagi == 'y' || mainLagi == 'Y');

    return 0;
}