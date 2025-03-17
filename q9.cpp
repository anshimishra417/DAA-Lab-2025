
#include <iostream>
#include <algorithm> // For sort()
using namespace std;

// Function to check for duplicates in the array
bool hasDuplicate(int arr[], int n) {
    sort(arr, arr + n); // Sorting the array (O(n log n))

    // Check for consecutive duplicates
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true; // Duplicate found
        }
    }
    return false; // No duplicates found
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (hasDuplicate(arr, n)) {
        cout << "Duplicate elements found." << endl;
    } else {
        cout << "No duplicate elements found." << endl;
    }

    return 0;
}
