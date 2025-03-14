#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tổng của một dòng
int sumOfRow(const vector<int>& row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
}

// Hàm tìm dòng có tổng lớn nhất
int findRowWithMaxSum(const vector<vector<int>>& matrix) {
    int maxSum = -1;
    int maxRowIndex = -1;
    for (size_t i = 0; i < matrix.size(); ++i) {
        int currentSum = sumOfRow(matrix[i]);
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

// Hàm sắp xếp các dòng theo tổng giảm dần
void sortRowsBySum(vector<vector<int>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        return sumOfRow(a) > sumOfRow(b);
    });
}

// Hàm nhập ma trận
void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    matrix.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Nhập phần tử tại (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

// Hàm in ma trận
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

    // Tìm dòng có tổng lớn nhất
    int maxRowIndex = findRowWithMaxSum(matrix);
    if (maxRowIndex != -1) {
        cout << "\nDòng có tổng lớn nhất là dòng " << maxRowIndex << " với tổng: " 
             << sumOfRow(matrix[maxRowIndex]) << endl;
    }

    // Sắp xếp các dòng theo tổng giảm dần
    sortRowsBySum(matrix);
    cout << "\nMa trận sau khi sắp xếp theo tổng dòng giảm dần:\n";
    printMatrix(matrix);

    return 0;
}
