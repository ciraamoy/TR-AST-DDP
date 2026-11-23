#include <stdio.h>

#define MERAH "\x1b[41m" //untuk warna
#define PUTIH "\x1b[47m"
#define RESET "\x1b[0m"

void menuBendera() {
    int tinggi, lebar, i, j;

    printf("\n=== BENDERA ===\n");
    printf("Masukkan tinggi bendera: ");
    scanf("%d", &tinggi);

    if (tinggi <= 0) {
        printf("Tinggi harus lebih dari 0!\n");
        return;
    }

    lebar = tinggi * 3;
    printf("\n");

    for (i = 1; i <= tinggi; i++) {
        if (i <= tinggi / 2) {
            printf(MERAH);
        } else {
            printf(PUTIH);
        }

        for (j = 0; j < lebar; j++) {
            printf(" ");
        }

        printf(RESET "\n");
    }
}

int main() {
    menuBendera();
    return 0;
}