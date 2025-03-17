#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of the key using binary search
int findFirstOccurrence(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;  // Continue searching on the left side
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to find the last occurrence of the key using binary search
int findLastOccurrence(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;  // Continue searching on the right side
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5, 6};
    int key;

    cout << "Enter the key to search: ";
    cin >> key;

    int firstIndex = findFirstOccurrence(arr, key);
    if (firstIndex == -1) {
        cout << "Key not found." << endl;
    } else {
        int lastIndex = findLastOccurrence(arr, key);
        int count = lastIndex - firstIndex + 1;
        cout << "Key " << key << " found with " << count << " occurrence(s)." << endl;
    }

    return 0;
}