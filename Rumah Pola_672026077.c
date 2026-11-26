#include <stdio.h>

int main() {
    int pilih, n, i, j;

    do {
        printf("\n=== RUMAH POLA ===\n");
        printf("1. Segitiga\n");
        printf("2. Segitiga Terbalik\n");
        printf("3. Piramida\n");
        printf("4. Persegi\n");
        printf("0. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);

        if (pilih >= 1 && pilih <= 4) {
            printf("Tinggi : ");
            scanf("%d", &n);
            printf("\n");
        }

        switch (pilih) {
            case 1:
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= i; j++)
                        printf("* ");
                    printf("\n");
                }
                break;
            case 2:
                for (i = n; i >= 1; i--) {
                    for (j = 1; j <= i; j++)
                        printf("* ");
                    printf("\n");
                }
                break;
            case 3:
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n - i; j++)
                        printf(" ");
                    for (j = 1; j <= 2 * i - 1; j++)
                        printf("*");
                    printf("\n");
                }
                break;
            case 4:
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++)
                        printf("* ");
                    printf("\n");
                }
                break;
            case 0:
                printf("Selesai.\n");
                break;
            default:
                printf("Pilihan salah!\n");
        }
    } while (pilih != 0);

    return 0;
}
