#include<bits/stdc++.h>
using namespace std;

// Function to perform Jump Search
int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n); // Optimal step size is sqrt(n)
    int prev = 0;

    // Finding the block where the element may be present
    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) // Key not present
            return -1;
    }

    // Performing linear search in the found block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int result = jumpSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}