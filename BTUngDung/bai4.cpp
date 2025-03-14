#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int findMaxPrime(const vector<vector<int>>& matrix) {
    int maxPrime = -1;
    for (const auto& row : matrix) {
        for (int num : row) {
            if (isPrime(num) && num > maxPrime) {
                maxPrime = num;
            }
        }
    }
    return maxPrime;
}

vector<int> findRowsWithPrimes(const vector<vector<int>>& matrix) {
    vector<int> rows;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (int num : matrix[i]) {
            if (isPrime(num)) {
                rows.push_back(i);
                break;
            }
        }
    }
    return rows;
}

vector<int> findRowsWithAllPrimes(const vector<vector<int>>& matrix) {
    vector<int> rows;
    for (size_t i = 0; i < matrix.size(); ++i) {
        bool allPrimes = true;
        for (int num : matrix[i]) {
            if (!isPrime(num)) {
                allPrimes = false;
                break;
            }
        }
        if (allPrimes) {
            rows.push_back(i);
        }
    }
    return rows;
}

void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    matrix.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Nhập phần tử tại (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Nhập số hàng: ";
    cin >> rows;
    cout << "Nhập số cột: ";
    cin >> cols;

    vector<vector<int>> matrix;
    inputMatrix(matrix, rows, cols);

    cout << "\nMa trận vừa nhập:\n";
    printMatrix(matrix);

    int maxPrime = findMaxPrime(matrix);
    if (maxPrime != -1) {
        cout << "\nSố nguyên tố lớn nhất trong ma trận: " << maxPrime << endl;
    } else {
        cout << "\nKhông có số nguyên tố trong ma trận." << endl;
    }

    vector<int> rowsWithPrimes = findRowsWithPrimes(matrix);
    cout << "\nCác hàng có ít nhất một số nguyên tố: ";
    for (int row : rowsWithPrimes) {
        cout << row << " ";
    }
    cout << endl;

    vector<int> rowsWithAllPrimes = findRowsWithAllPrimes(matrix);
    cout << "\nCác hàng chỉ chứa toàn số nguyên tố: ";
    for (int row : rowsWithAllPrimes) {
        cout << row << " ";
    }
    cout << endl;

    return 0;
}
