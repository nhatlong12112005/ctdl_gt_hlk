#include <iostream>
#include <vector>
using namespace std;

// Hàm phân chia dãy và trả về vị trí của pivot (Quick Sort)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm đệ quy Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm trộn hai mảng con (Merge Sort)
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Hàm đệ quy Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Hàm heapify để tạo max-heap (Heap Sort)
void heapify(vector<int>& arr, int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) max = left;
    if (right < n && arr[right] > arr[max]) max = right;

    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

// Hàm Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Hàm hiển thị mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};

    // Quick Sort
    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size() - 1);
    cout << "Quick Sort: ";
    printArray(quickArr);

    // Merge Sort
    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "Merge Sort: ";
    printArray(mergeArr);

    // Heap Sort
    vector<int> heapArr = arr;
    heapSort(heapArr);
    cout << "Heap Sort: ";
    printArray(heapArr);

    return 0;
}
