#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    int maSo;                  // Mã số (số nguyên dương)
    string hoVaDem;            // Họ và đệm (tối đa 20 ký tự)
    string ten;                // Tên sinh viên (tối đa 40 ký tự)
    int ngaySinh, thangSinh, namSinh; // Ngày, tháng, năm sinh (số nguyên dương)
    string phai;               // Giới tính ("Nam" hoặc "Nữ")
    double diemTrungBinh;       // Điểm trung bình (0.00 -> 10.00)
};

// Hàm nhập thông tin sinh viên
void nhapSinhVien(SinhVien &sv) {
    cout << "Nhập mã số: ";
    cin >> sv.maSo;
    cin.ignore(); // Xóa bộ đệm tránh lỗi nhập chuỗi

    cout << "Nhập họ và đệm: ";
    getline(cin, sv.hoVaDem);
    
    cout << "Nhập tên: ";
    getline(cin, sv.ten);
    
    cout << "Nhập ngày sinh (dd mm yyyy): ";
    cin >> sv.ngaySinh >> sv.thangSinh >> sv.namSinh;

    cout << "Nhập giới tính (Nam/Nữ): ";
    cin >> sv.phai;

    cout << "Nhập điểm trung bình: ";
    cin >> sv.diemTrungBinh;

    // Đảm bảo dữ liệu hợp lệ
    if (sv.diemTrungBinh < 0.0 || sv.diemTrungBinh > 10.0) {
        cout << "Điểm trung bình không hợp lệ! Đặt về 0.0.\n";
        sv.diemTrungBinh = 0.0;
    }
}

// Hàm xuất thông tin sinh viên
void xuatSinhVien(const SinhVien &sv) {
    cout << "\n--- Thông tin sinh viên ---\n";
    cout << "Mã số: " << sv.maSo << endl;
    cout << "Họ và đệm: " << sv.hoVaDem << endl;
    cout << "Tên: " << sv.ten << endl;
    cout << "Ngày sinh: " << sv.ngaySinh << "/" << sv.thangSinh << "/" << sv.namSinh << endl;
    cout << "Giới tính: " << sv.phai << endl;
    cout << "Điểm trung bình: " << fixed << setprecision(2) << sv.diemTrungBinh << endl;
}

int main() {
    SinhVien sv;
    nhapSinhVien(sv);
    xuatSinhVien(sv);
    return 0;
}
