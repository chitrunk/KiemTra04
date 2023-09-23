#include <stdio.h>
#include <stdbool.h>

// H�m ki?m tra xem m?t s? c� ph?i l� s? nguy�n t? hay kh�ng
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// H�m nh?p m?ng
void inputArray(int a[], int n) {
    printf("Nh?p %d ph?n t? cho m?ng:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nh?p ph?n t? th? %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// H�m xu?t m?ng
void printArray(int a[], int n) {
    printf("M?ng v?a nh?p l�:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// H�m t�m s? nguy�n t? d?u ti�n trong m?ng v� v? tr� c?a n�
void findFirstPrime(int a[], int n) {
    int firstPrime = -1;
    int firstPrimeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            firstPrime = a[i];
            firstPrimeIndex = i;
            break; // Khi t�m th?y s? nguy�n t? d?u ti�n, tho�t kh?i v�ng l?p
        }
    }

    if (firstPrime != -1) {
        printf("S? nguy�n t? d?u ti�n trong m?ng l�: %d, t?i v? tr� %d\n", firstPrime, firstPrimeIndex);
    } else {
        printf("Kh�ng c� s? nguy�n t? trong m?ng.\n");
    }
}

int main() {
    int n;
    printf("Nh?p s? ph?n t? c?a m?ng: ");
    scanf("%d", &n);
    
    int a[n];
    inputArray(a, n);
    
    char choice;

    while (1) {
        printf("Ch?n ch?c nang:\n");
        printf("A. T�m v� in ra s? nguy�n t? d?u ti�n v� v? tr� c?a n� trong m?ng.\n");
        printf("B. Xu?t m?ng.\n");
        printf("C. Tho�t.\n");
        printf("Ch?n: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a':
                findFirstPrime(a, n);
                break;
            case 'B':
            case 'b':
                printArray(a, n);
                break;
            case 'C':
            case 'c':
                printf("K?t th�c chuong tr�nh.\n");
                return 0;
            default:
                printf("L?a ch?n kh�ng h?p l?.\n");
                break;
        }
    }

    return 0;
}
