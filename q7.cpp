#include <iostream>
using namespace std;

// Function to perform insertion sort and count comparisons and shifts
void insertionSort(int arr[], int n, int &comparisons, int &shifts) {
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare and shift elements
        while (j >= 0 && arr[j] > key) {
            comparisons++;  // Count comparison
            arr[j + 1] = arr[j];
            shifts++;       // Count shift
            j--;
        }
        if (j >= 0) comparisons++;  // Final comparison when condition fails

        arr[j + 1] = key;
        if (j + 1 != i) shifts++;   // Count shift only if insertion occurs
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {9, 3, 1, 7, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int comparisons = 0, shifts = 0;

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n, comparisons, shifts);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;

    return 0;
}