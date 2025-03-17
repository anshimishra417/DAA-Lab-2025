#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index is the minimum
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Counting the comparison
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update the minimum index
            }
        }
        // Swap if needed
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++; // Counting the swap
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11}; // Example array

    cout << "Original array: ";
    printArray(arr);

    int comparisons = 0;
    int swaps = 0;

    selectionSort(arr, comparisons, swaps);

    cout << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}