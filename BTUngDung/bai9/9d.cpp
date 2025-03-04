#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    int maSo;
    string hoVaDem;
    string ten;
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

        cout << "Nhập điểm trung bình: ";
        cin >> sv.diemTrungBinh;

        danhSach.push_back(sv);
    }
}

// Hàm lưu chỉ mục vào file
void luuChiMuc(const vector<int> &indexList, const string &fileName) {
    ofstream file(fileName);
    if (!file) {
        cout << "Không thể mở file " << fileName << " để ghi!\n";
        return;
    }

    for (int index : indexList) {
        file << index << endl;
    }

    file.close();
    cout << "Đã lưu chỉ mục vào file " << fileName << " thành công!\n";
}

// Hàm tạo danh sách chỉ mục theo Mã số
vector<int> chiMucTheoMaSo(const vector<SinhVien> &danhSach) {
    vector<int> indexList(danhSach.size());
    for (int i = 0; i < danhSach.size(); i++)
        indexList[i] = danhSach[i].maSo;

    sort(indexList.begin(), indexList.end());
    return indexList;
}

// Hàm tạo danh sách chỉ mục theo Tên (A → Z)
vector<int> chiMucTheoTen(const vector<SinhVien> &danhSach) {
    vector<pair<string, int>> indexed;
    for (const auto &sv : danhSach)
        indexed.emplace_back(sv.ten + " " + sv.hoVaDem, sv.maSo);

    sort(indexed.begin(), indexed.end());

    vector<int> indexList;
    for (const auto &p : indexed)
        indexList.push_back(p.second);
    return indexList;
}

// Hàm tạo danh sách chỉ mục theo Điểm trung bình (giảm dần)
vector<int> chiMucTheoDiem(const vector<SinhVien> &danhSach) {
    vector<pair<double, int>> indexed;
    for (const auto &sv : danhSach)
        indexed.emplace_back(sv.diemTrungBinh, sv.maSo);

    sort(indexed.rbegin(), indexed.rend());

    vector<int> indexList;
    for (const auto &p : indexed)
        indexList.push_back(p.second);
    return indexList;
}

int main() {
    vector<SinhVien> danhSach;
    int soLuong;

    do {
        cout << "Nhập số lượng sinh viên (<= 2): ";
        cin >> soLuong;
    } while (soLuong < 2);

    nhapDanhSachSinhVien(danhSach, soLuong);

    // Tạo và lưu chỉ mục theo Mã số
    vector<int> indexMaSo = chiMucTheoMaSo(danhSach);
    luuChiMuc(indexMaSo, "SVMASO.IDX");

    // Tạo và lưu chỉ mục theo Tên
    vector<int> indexTen = chiMucTheoTen(danhSach);
    luuChiMuc(indexTen, "SVTH.IDX");

    // Tạo và lưu chỉ mục theo Điểm trung bình
    vector<int> indexDiem = chiMucTheoDiem(danhSach);
    luuChiMuc(indexDiem, "SVDTB.IDX");

    return 0;
}
