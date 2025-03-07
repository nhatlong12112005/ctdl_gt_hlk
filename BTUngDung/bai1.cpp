#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += abs(num % 10);
        num /= 10;
    }
    return sum;
}

// Tìm vị trí của một phần tử lớn nhất trong mảng
int findMaxPosition(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Sắp xếp mảng theo tổng các chữ số của phần tử
void sortByDigitSum(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sumOfDigits(arr[i]) > sumOfDigits(arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Xóa các số nguyên tố khỏi mảng
int removePrimes(int arr[], int n) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (!isPrime(arr[i])) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

   
    int maxPos = findMaxPosition(arr, n);
    cout << "Vi tri cua phan tu lon nhat: " << maxPos << endl;

    
    sortByDigitSum(arr, n);
    cout << "Sap xep theo tong cac chu so: ";
    printArray(arr, n);

    n = removePrimes(arr, n);
    cout << "Mang sau khi xoa cac so nguyen to: ";
    printArray(arr, n);

    return 0;
}
