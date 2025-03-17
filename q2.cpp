#include <iostream>
using namespace std;

// Binary Search Function
int binarySearch(int arr[], int left, int right, int key, int &comparisons) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        comparisons++;
        if (arr[mid] == key) 
            return mid; // Key found
        
        comparisons++;
        if (arr[mid] < key) 
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Key not found
}

int main() {
    int n, key, comparisons = 0;

    // Input array size and elements
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Input key to search
    cout << "Enter key to search: ";
    cin >> key;

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key, comparisons);

    // Display result
    if (result != -1)
        cout << "Element found at index " << result << " with " << comparisons << " comparisons." << endl;
    else
        cout << "Element not found after " << comparisons << " comparisons." << endl;

    return 0;
}