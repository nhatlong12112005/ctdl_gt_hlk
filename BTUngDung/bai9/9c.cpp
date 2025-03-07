#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    int maSo;
    string hoVaDem;
    string ten;
    int ngaySinh, thangSinh, namSinh;
    string phai;
    double diemTrungBinh;
};

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(vector<SinhVien> &danhSach, int soLuong) {
    set<int> maSoDaNhap;

    for (int i = 0; i < soLuong; i++) {
        SinhVien sv;
        cout << "\nNhập thông tin sinh viên thứ " << i + 1 << ":\n";

        do {
            cout << "Nhập mã số: ";
            cin >> sv.maSo;
            if (maSoDaNhap.count(sv.maSo)) {
                cout << "Mã số đã tồn tại! Vui lòng nhập lại.\n";
            }
        } while (maSoDaNhap.count(sv.maSo));
        maSoDaNhap.insert(sv.maSo);
        cin.ignore();

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

        if (sv.diemTrungBinh < 0.0 || sv.diemTrungBinh > 10.0) {
            cout << "Điểm trung bình không hợp lệ! Đặt về 0.0.\n";
            sv.diemTrungBinh = 0.0;
        }

        danhSach.push_back(sv);
    }
}

// Hàm lưu danh sách vào file
void luuFile(const vector<SinhVien> &danhSach, const string &fileName) {
    ofstream file(fileName);
    if (!file) {
        cout << "Không thể mở file để ghi!\n";
        return;
    }

    file << "--- DANH SÁCH SINH VIÊN ---\n";
    for (const auto &sv : danhSach) {
        file << sv.maSo << " | "
             << sv.hoVaDem << " " << sv.ten << " | "
             << sv.ngaySinh << "/" << sv.thangSinh << "/" << sv.namSinh << " | "
             << sv.phai << " | "
             << fixed << setprecision(2) << sv.diemTrungBinh << endl;
    }

    file.close();
    cout << "Đã lưu danh sách vào file " << fileName << " thành công!\n";
}

// Hàm sắp xếp theo Mã số tăng dần
void sapXepTheoMaSo(vector<SinhVien> &danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const SinhVien &a, const SinhVien &b) {
        return a.maSo < b.maSo;
    });
}

// Hàm sắp xếp theo Tên tăng dần, nếu cùng tên thì xét Họ và đệm
void sapXepTheoTen(vector<SinhVien> &danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const SinhVien &a, const SinhVien &b) {
        if (a.ten == b.ten)
            return a.hoVaDem < b.hoVaDem;
        return a.ten < b.ten;
    });
}

// Hàm sắp xếp theo Điểm trung bình giảm dần
void sapXepTheoDiem(vector<SinhVien> &danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const SinhVien &a, const SinhVien &b) {
        return a.diemTrungBinh > b.diemTrungBinh;
    });
}

int main() {
    vector<SinhVien> danhSach;
    int soLuong;

    do {
        cout << "Nhập số lượng sinh viên (<= 2): ";
        cin >> soLuong;
    } while (soLuong < 2);

    nhapDanhSachSinhVien(danhSach, soLuong);

    // Sắp xếp theo từng tiêu chí và lưu vào các file khác nhau
    vector<SinhVien> dsMaSo = danhSach;
    sapXepTheoMaSo(dsMaSo);
    luuFile(dsMaSo, "SINHVIEN_MASO.DAT");

    vector<SinhVien> dsTen = danhSach;
    sapXepTheoTen(dsTen);
    luuFile(dsTen, "SINHVIEN_TEN.DAT");

    vector<SinhVien> dsDiem = danhSach;
    sapXepTheoDiem(dsDiem);
    luuFile(dsDiem, "SINHVIEN_DIEM.DAT");

    return 0;
}
