#include <iostream>
#include <unordered_set>
using namespace std;

// Function to count pairs with the given difference K
int countPairsWithDifference(int arr[], int n, int k) {
    unordered_set<int> elements;
    int count = 0;

    // Insert array elements into the set
    for (int i = 0; i < n; i++) {
        elements.insert(arr[i]);
    }

    // Check for each element if (element + k) exists in the set
    for (int i = 0; i < n; i++) {
        if (elements.find(arr[i] + k) != elements.end()) {
            count++;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = countPairsWithDifference(arr, n, k);
    cout << "Number of pairs with difference " << k << ": " << result << endl;

    return 0;
}