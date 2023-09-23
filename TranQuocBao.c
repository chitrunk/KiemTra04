#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Nhap mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    while (1) {
        printf("\nChon chuc nang:\n");
        printf("1. Tim so nguyen to dau tien va vi tri cua no.\n");
        printf("2. Xuat mang.\n");
        printf("3. Thoat.\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int firstPrimeIndex = -1;
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        firstPrimeIndex = i;
                        break;
                    }
                }
                if (firstPrimeIndex != -1) {
                    printf("So nguyen to dau tien la %d, tai vi tri %d.\n", arr[firstPrimeIndex], firstPrimeIndex);
                } else {
                    printf("Khong co so nguyen to trong mang.\n");
                }
                break;
            }
            case 2: {
                printf("Mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                return 0;
            }
            default: {
                printf("Chon khong hop le. Vui long chon lai.\n");
            }
        }
    }
    
    return 0;
}
