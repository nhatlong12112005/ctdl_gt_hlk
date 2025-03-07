#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Hàm tạo mảng ngẫu nhiên
void generateRandomArray(vector<int>& arr, int n) {
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  // Giá trị từ 0 đến 99999
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr, long long &comp, long long &swap) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap++;
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high, long long &comp, long long &swap) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            comp++;
            if (arr[j] < pivot) {
                i++;
                swap++;
                std::swap(arr[i], arr[j]);
            }
        }
        swap++;
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1, comp, swap);
        quickSort(arr, pi + 1, high, comp, swap);
    }
}

// Hàm tính thời gian chạy của thuật toán
template <typename Func>
double measureTime(Func sortFunc, vector<int> arr, long long &comp, long long &swap) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, comp, swap);
    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count();
}

int main() {
    srand(time(nullptr)); // Seed cho hàm rand()
    
    vector<int> sizes = {10, 100, 200, 500, 1000, 5000, 10000};
    int numTests = 5; // Số lần thực nghiệm

    for (int n : sizes) {
        cout << "\nKích thước mảng: " << n << endl;

        double totalTimeBubble = 0, totalTimeQuick = 0;
        long long totalCompBubble = 0, totalSwapBubble = 0;
        long long totalCompQuick = 0, totalSwapQuick = 0;

        for (int t = 0; t < numTests; t++) {
            vector<int> arr;
            generateRandomArray(arr, n);

            long long compBubble = 0, swapBubble = 0;
            long long compQuick = 0, swapQuick = 0;

            vector<int> tempArr = arr;
            totalTimeBubble += measureTime(bubbleSort, tempArr, compBubble, swapBubble);
            totalCompBubble += compBubble;
            totalSwapBubble += swapBubble;

            tempArr = arr;
            auto start = high_resolution_clock::now();
            quickSort(tempArr, 0, n - 1, compQuick, swapQuick);
            auto end = high_resolution_clock::now();
            totalTimeQuick += duration<double>(end - start).count();
            totalCompQuick += compQuick;
            totalSwapQuick += swapQuick;
        }

        cout << "Bubble Sort: Thời gian trung bình: " << totalTimeBubble / numTests << " s, So sánh: " << totalCompBubble / numTests << ", Đổi chỗ: " << totalSwapBubble / numTests << endl;
        cout << "Quick Sort: Thời gian trung bình: " << totalTimeQuick / numTests << " s, So sánh: " << totalCompQuick / numTests << ", Đổi chỗ: " << totalSwapQuick / numTests << endl;
    }
    return 0;
}
