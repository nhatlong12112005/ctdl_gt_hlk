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

// Hàm sắp xếp chọn (Selection Sort)
void selectionSort(vector<SoHang> &danhSachSoHang) {
    int n = danhSachSoHang.size();
    for (int i = 0; i < n - 1; i++) {
        // Tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (danhSachSoHang[j].bac < danhSachSoHang[minIndex].bac) {
                minIndex = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của đoạn chưa sắp xếp
        if (minIndex != i) {
            swap(danhSachSoHang[i], danhSachSoHang[minIndex]);
        }
    }
}

// Hàm nhập danh sách số hạng
void nhapDanhSach(vector<SoHang> &danhSachSoHang, int n) {
    for (int i = 0; i < n; i++) {
        SoHang soHang;
        cout << "Nhập hệ số của số hạng thứ " << i + 1 << ": ";
        cin >> soHang.heSo;
        cout << "Nhập bậc của số hạng thứ " << i + 1 << ": ";
        cin >> soHang.bac;
        danhSachSoHang.push_back(soHang);
    }
}

// Hàm hiển thị danh sách số hạng
void hienThiDanhSach(const vector<SoHang> &danhSachSoHang) {
    for (const SoHang &soHang : danhSachSoHang) {
        cout << "Hệ số: " << soHang.heSo << ", Bậc: " << soHang.bac << endl;
    }
}

int main() {
    int n;
    cout << "Nhập số lượng số hạng: ";
    cin >> n;

    vector<SoHang> danhSachSoHang;
    nhapDanhSach(danhSachSoHang, n);
    
    cout << "\nDanh sách số hạng trước khi sắp xếp:\n";
    hienThiDanhSach(danhSachSoHang);

    selectionSort(danhSachSoHang);
    
    cout << "\nDanh sách số hạng sau khi sắp xếp theo bậc tăng dần:\n";
    hienThiDanhSach(danhSachSoHang);
    
    return 0;
}