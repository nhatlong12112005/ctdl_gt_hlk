#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

struct SinhVien {
    int maSo;
    char hoDem[21];
    char ten[41];
    int ngay, thang, nam;
    char phai[4];
    float diemTB;
};

void nhapDanhSach(vector<SinhVien>& danhSach) {
    ofstream file("SINHVIEN.DAT", ios::binary);
    if (!file) {
        cout << "Khong the mo file SINHVIEN.DAT de ghi!\n";
        return;
    }
    
    set<int> maSoDaNhap;
    int n;
    cout << "Nhap so luong sinh vien (toi thieu 10): ";
    cin >> n;
    while (n < 10) {
        cout << "So luong phai >= 10. Nhap lai: ";
        cin >> n;
    }
    
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "Nhap ma so: ";
        cin >> sv.maSo;
        while (maSoDaNhap.count(sv.maSo)) {
            cout << "Ma so da ton tai! Nhap lai: ";
            cin >> sv.maSo;
        }
        maSoDaNhap.insert(sv.maSo);
        
        cout << "Nhap ho va dem: ";
        cin.ignore();
        cin.getline(sv.hoDem, 21);
        
        cout << "Nhap ten: ";
        cin.getline(sv.ten, 41);
        
        cout << "Nhap ngay thang nam sinh (dd mm yyyy): ";
        cin >> sv.ngay >> sv.thang >> sv.nam;
        
        cout << "Nhap phai (Nam/Nu): ";
        cin >> sv.phai;
        
        cout << "Nhap diem trung binh: ";
        cin >> sv.diemTB;
        
        danhSach.push_back(sv);
        file.write(reinterpret_cast<char*>(&sv), sizeof(SinhVien));
    }
    file.close();
}

void docDanhSach(vector<SinhVien>& danhSach) {
    ifstream file("SINHVIEN.DAT", ios::binary);
    if (!file) {
        cout << "Khong the mo file SINHVIEN.DAT!\n";
        return;
    }
    SinhVien sv;
    while (file.read(reinterpret_cast<char*>(&sv), sizeof(SinhVien))) {
        danhSach.push_back(sv);
    }
    file.close();
}

void luuChiMuc(const vector<int>& indexList, const string& filename) {
    ofstream file(filename, ios::binary);
    file.write(reinterpret_cast<const char*>(indexList.data()), indexList.size() * sizeof(int));
    file.close();
}

void sapXepVaLuuChiMuc(vector<SinhVien>& danhSach) {
    vector<int> indexMaSo(danhSach.size()), indexTen(danhSach.size()), indexDiemTB(danhSach.size());
    for (int i = 0; i < danhSach.size(); i++) {
        indexMaSo[i] = indexTen[i] = indexDiemTB[i] = i;
    }
    
    sort(indexMaSo.begin(), indexMaSo.end(), [&](int a, int b) {
        return danhSach[a].maSo < danhSach[b].maSo;
    });
    sort(indexTen.begin(), indexTen.end(), [&](int a, int b) {
        int cmp = strcmp(danhSach[a].ten, danhSach[b].ten);
        if (cmp == 0) return strcmp(danhSach[a].hoDem, danhSach[b].hoDem) < 0;
        return cmp < 0;
    });
    sort(indexDiemTB.begin(), indexDiemTB.end(), [&](int a, int b) {
        return danhSach[a].diemTB > danhSach[b].diemTB;
    });
    
    luuChiMuc(indexMaSo, "SVMASO.IDX");
    luuChiMuc(indexTen, "SVTH.IDX");
    luuChiMuc(indexDiemTB, "SVDTB.IDX");
}

void hienThiTheoChiMuc(vector<SinhVien>& danhSach, const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Khong the mo file chi muc: " << filename << "\n";
        return;
    }
    vector<int> indexList(danhSach.size());
    file.read(reinterpret_cast<char*>(indexList.data()), danhSach.size() * sizeof(int));
    file.close();
    
    for (int i : indexList) {
        cout << danhSach[i].maSo << " - " << danhSach[i].hoDem << " " << danhSach[i].ten
             << " - Diem TB: " << danhSach[i].diemTB << endl;
    }
}

int main() {
    vector<SinhVien> danhSach;
    nhapDanhSach(danhSach);
    
    docDanhSach(danhSach);
    if (danhSach.empty()) return 1;
    
    sapXepVaLuuChiMuc(danhSach);
    
    cout << "\nDanh sach theo Ma So:" << endl;
    hienThiTheoChiMuc(danhSach, "SVMASO.IDX");
    
    cout << "\nDanh sach theo Ten:" << endl;
    hienThiTheoChiMuc(danhSach, "SVTH.IDX");
    
    cout << "\nDanh sach theo Diem Trung Binh:" << endl;
    hienThiTheoChiMuc(danhSach, "SVDTB.IDX");
    
    return 0;
}
