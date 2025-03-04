#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

// Đọc dữ liệu từ file
void readData(const string& filename, int arr[], int &n) {
    ifstream file(filename);
    n = 0;
    while (file >> arr[n]) {
        n++;
    }
    file.close();
}

// Ghi kết quả vào file
void writeResult(const string& filename, const string& algorithm, int arr[], int n) {
    ofstream file(filename, ios::app);
    file << algorithm << ":\n";
    for (int i = 0; i < n; i++) {
        file << arr[i] << " ";
    }
    file << "\n\n";
    file.close();
}

// Sắp xếp đổi chỗ trực tiếp
void interchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Sắp xếp chọn trực tiếp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Sắp xếp chèn trực tiếp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Sắp xếp nổi bọt
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    
    ofstream clearFile(outputFile, ios::trunc); // Xóa dữ liệu cũ
    clearFile.close();

    int arr[MAX_SIZE], n;

    void (*algorithms[])(int[], int) = {interchangeSort, selectionSort, insertionSort, bubbleSort};
    string algorithmNames[] = {"Interchange Sort", "Selection Sort", "Insertion Sort", "Bubble Sort"};

    for (int i = 0; i < 4; i++) {
        readData(inputFile, arr, n);
        algorithms[i](arr, n);
        writeResult(outputFile, algorithmNames[i], arr, n);
    }

    return 0;
}
