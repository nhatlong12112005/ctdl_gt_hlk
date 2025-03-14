#include <iostream>
#include <vector>
using namespace std;

struct SoHang {
    double heSo;
    int bac;
};

// Hàm hoán đổi hai phần tử
void swap(SoHang &a, SoHang &b) {
    SoHang temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp chọn (Selection Sort) theo bậc tăng dần
void selectionSort(vector<SoHang> &danhSachSoHang) {
    int n = danhSachSoHang.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (danhSachSoHang[j].bac < danhSachSoHang[minIndex].bac) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(danhSachSoHang[i], danhSachSoHang[minIndex]);
        }
    }
}

// Hàm nhập danh sách số hạng
void nhapDanhSach(vector<SoHang> &danhSach, int n) {
    danhSach.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhập hệ số của số hạng thứ " << i + 1 << ": ";
        cin >> danhSach[i].heSo;
        cout << "Nhập bậc của số hạng thứ " << i + 1 << ": ";
        cin >> danhSach[i].bac;
    }
}

// Hàm in danh sách số hạng
void inDanhSach(const vector<SoHang> &danhSach) {
    for (const auto &soHang : danhSach) {
        cout << soHang.heSo << "x^" << soHang.bac << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhập số lượng số hạng: ";
    cin >> n;

    vector<SoHang> danhSachSoHang;
    nhapDanhSach(danhSachSoHang, n);

    cout << "\nDanh sách số hạng trước khi sắp xếp:\n";
    inDanhSach(danhSachSoHang);

    selectionSort(danhSachSoHang);

    cout << "\nDanh sách số hạng sau khi sắp xếp theo bậc tăng dần:\n";
    inDanhSach(danhSachSoHang);

    return 0;
}
