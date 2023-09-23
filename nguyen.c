#include <stdio.h>
#include <stdbool.h>

// Hàm ki?m tra xem m?t s? có ph?i là s? nguyên t? hay không
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm nh?p m?ng
void inputArray(int a[], int n) {
    printf("Nh?p %d ph?n t? cho m?ng:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nh?p ph?n t? th? %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Hàm xu?t m?ng
void printArray(int a[], int n) {
    printf("M?ng v?a nh?p là:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm tìm s? nguyên t? d?u tiên trong m?ng và v? trí c?a nó
void findFirstPrime(int a[], int n) {
    int firstPrime = -1;
    int firstPrimeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            firstPrime = a[i];
            firstPrimeIndex = i;
            break; // Khi tìm th?y s? nguyên t? d?u tiên, thoát kh?i vòng l?p
        }
    }

    if (firstPrime != -1) {
        printf("S? nguyên t? d?u tiên trong m?ng là: %d, t?i v? trí %d\n", firstPrime, firstPrimeIndex);
    } else {
        printf("Không có s? nguyên t? trong m?ng.\n");
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
        printf("A. Tìm và in ra s? nguyên t? d?u tiên và v? trí c?a nó trong m?ng.\n");
        printf("B. Xu?t m?ng.\n");
        printf("C. Thoát.\n");
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
                printf("K?t thúc chuong trình.\n");
                return 0;
            default:
                printf("L?a ch?n không h?p l?.\n");
                break;
        }
    }

    return 0;
}
