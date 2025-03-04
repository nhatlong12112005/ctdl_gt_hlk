#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
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
    set<int> maSoDaNhap; // Dùng tập hợp để kiểm tra trùng mã số

    for (int i = 0; i < soLuong; i++) {
        SinhVien sv;
        cout << "\nNhập thông tin sinh viên thứ " << i + 1 << ":\n";

        // Nhập mã số và kiểm tra trùng
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

        // Kiểm tra giá trị hợp lệ
        if (sv.diemTrungBinh < 0.0 || sv.diemTrungBinh > 10.0) {
            cout << "Điểm trung bình không hợp lệ! Đặt về 0.0.\n";
            sv.diemTrungBinh = 0.0;
        }

        danhSach.push_back(sv);
    }
}

// Hàm lưu danh sách sinh viên vào tập tin bằng freopen
void luuFileFreopen(const vector<SinhVien> &danhSach, const string &fileName) {
    freopen(fileName.c_str(), "w", stdout); // Ghi toàn bộ dữ liệu vào file

    cout << "--- DANH SÁCH SINH VIÊN ---\n";
    for (const auto &sv : danhSach) {
        cout << sv.maSo << " | "
             << sv.hoVaDem << " " << sv.ten << " | "
             << sv.ngaySinh << "/" << sv.thangSinh << "/" << sv.namSinh << " | "
             << sv.phai << " | "
             << fixed << setprecision(2) << sv.diemTrungBinh << endl;
    }

    fclose(stdout); // Đóng file
    freopen("/dev/tty", "w", stdout); // Khôi phục stdout về màn hình (Linux/Mac)
    // freopen("CON", "w", stdout); // Windows
    cout << "Đã lưu danh sách vào file " << fileName << " thành công!\n";
}

// Hàm đọc file bằng freopen và hiển thị lên màn hình
void docFileFreopen(const string &fileName) {
    freopen(fileName.c_str(), "r", stdin); // Mở file để đọc từ stdin

    string line;
    cout << "\n--- Nội dung trong file ---\n";
    while (getline(cin, line)) {
        cout << line << endl;
    }

    fclose(stdin); // Đóng file
    freopen("/dev/tty", "r", stdin); // Khôi phục stdin về bàn phím (Linux/Mac)
    // freopen("CON", "r", stdin); // Windows
}

int main() {
    vector<SinhVien> danhSach;
    int soLuong;

    do {
        cout << "Nhập số lượng sinh viên (<= 2 ): ";
        cin >> soLuong;
    } while (soLuong < 2);

    nhapDanhSachSinhVien(danhSach, soLuong);
    luuFileFreopen(danhSach, "SINHVIEN.DAT");
    docFileFreopen("SINHVIEN.DAT");

    return 0;
}
