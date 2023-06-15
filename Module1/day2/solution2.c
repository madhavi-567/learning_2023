#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    unsigned char *byteA = (unsigned char *)a;
    unsigned char *byteB = (unsigned char *)b;

    for (size_t i = 0; i < size; i++) {
        unsigned char temp = byteA[i];
        byteA[i] = byteB[i];
        byteB[i] = temp;
    }
}

int main() {
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    double a = 3.14;
    double b = 2.71;

    printf("Before swap: a = %lf, b = %lf\n", a, b);
    swap(&a, &b, sizeof(double));
    printf("After swap: a = %lf, b = %lf\n", a, b);

    return 0;
}