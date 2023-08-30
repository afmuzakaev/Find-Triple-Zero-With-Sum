#include <iostream>
#include <algorithm>

using namespace std;

bool hasZeroSumTriplet(int arr[], int n) {
    // Sort the array in ascending order
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        int target = -arr[i];  // Find a pair that sums up to -arr[i]

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                return true;  // Triplet found
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return false;  // No triplet found
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (hasZeroSumTriplet(arr, n)) {
        cout << "Output: 1 (Triplet with zero sum found)" << endl;
    } else {
        cout << "Output: 0 (No triplet with zero sum found)" << endl;
    }

    return 0;
}
