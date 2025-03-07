#include <iostream>
using namespace std;

void sapXepChanLe(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        // tim so le ben trai
        while (left < right && a[left] % 2 == 0) left++;
        // tim so chan ben phai
        while (left < right && a[right] % 2 != 0) right--;
        if (left < right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int a[10] = {2, 1, 6, 7, 5, 11, 4, 3, 9, 10};
    sapXepChanLe(a, 10);

    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
}
