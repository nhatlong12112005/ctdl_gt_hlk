#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    int maSo;
    string hoVaDem;
    string ten;
    double diemTrungBinh;
};

// Hàm đọc danh sách sinh viên từ file SINHVIEN.DAT
vector<SinhVien> docDanhSachSinhVien(const string &fileName) {
    vector<SinhVien> danhSach;
    ifstream file(fileName, ios::binary);
    
    if (!file) {
        cout << "Không thể mở file " << fileName << "!\n";
        return danhSach;
    }

    SinhVien sv;
    while (file.read(reinterpret_cast<char*>(&sv), sizeof(SinhVien))) {
        danhSach.push_back(sv);
    }

    file.close();
    return danhSach;
}

// Hàm đọc danh sách chỉ mục từ file
vector<int> docChiMuc(const string &fileName) {
    vector<int> indexList;
    ifstream file(fileName);
    
    if (!file) {
        cout << "Không thể mở file " << fileName << "!\n";
        return indexList;
    }

    int id;
    while (file >> id) {
        indexList.push_back(id);
    }

    file.close();
    return indexList;
}

// Hàm hiển thị danh sách theo thứ tự chỉ mục
void hienThiTheoChiMuc(const vector<SinhVien> &danhSach, const vector<int> &indexList, const string &title) {
    cout << "\n==== " << title << " ====\n";
    
    // Tạo bảng ánh xạ mã số sinh viên → thông tin sinh viên
    map<int, SinhVien> danhSachMap;
    for (const auto &sv : danhSach) {
        danhSachMap[sv.maSo] = sv;
    }

    // Hiển thị danh sách theo thứ tự chỉ mục
    for (int id : indexList) {
        if (danhSachMap.find(id) != danhSachMap.end()) {
            SinhVien sv = danhSachMap[id];
            cout << sv.maSo << " - " << sv.hoVaDem << " " << sv.ten << " - " << sv.diemTrungBinh << endl;
        }
    }
}

int main() {
    // Đọc danh sách sinh viên từ file SINHVIEN.DAT
    vector<SinhVien> danhSach = docDanhSachSinhVien("SINHVIEN.DAT");

    if (danhSach.empty()) {
        cout << "Không có dữ liệu sinh viên!\n";
        return 1;
    }

    // Đọc danh sách chỉ mục từ các file
    vector<int> indexMaSo = docChiMuc("SVMASO.IDX");
    vector<int> indexTen = docChiMuc("SVTH.IDX");
    vector<int> indexDiem = docChiMuc("SVDTB.IDX");

    // Hiển thị danh sách theo từng chỉ mục
    hienThiTheoChiMuc(danhSach, indexMaSo, "DANH SÁCH SẮP XẾP THEO MÃ SỐ");
    hienThiTheoChiMuc(danhSach, indexTen, "DANH SÁCH SẮP XẾP THEO TÊN");
    hienThiTheoChiMuc(danhSach, indexDiem, "DANH SÁCH SẮP XẾP THEO ĐIỂM TRUNG BÌNH");

    return 0;
}
