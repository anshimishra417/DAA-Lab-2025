#include <iostream>
#include <vector>
using namespace std;

// Function to find indices i, j, k such that arr[i] + arr[j] = arr[k]
void findTriplet(const vector<int>& arr) {
    int n = arr.size();
    
    // Iterate through each possible k
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        
        // Use two pointers to find valid i and j
        while (i < j) {
            if (arr[i] + arr[j] == arr[k]) {
                cout << "Indices found: i = " << i << ", j = " << j << ", k = " << k << endl;
                return;  // Exit after finding the first valid triplet
            } else if (arr[i] + arr[j] < arr[k]) {
                i++; // Move the left pointer right to increase the sum
            } else {
                j--; // Move the right pointer left to decrease the sum
            }
        }
    }
    cout << "No such indices found." << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 8, 13, 21};
    findTriplet(arr);
    return 0;
}