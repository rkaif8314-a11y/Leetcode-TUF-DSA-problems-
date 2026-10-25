#include <bits/stdc++.h>
using namespace std;

// Return the largest number in a non-empty array.
int largestElement(vector<int>& arr) {
    // Start by treating the first element as the largest.
    int largest = arr[0];

    // Begin at index 1 because index 0 is already stored in largest.
    for (int i = 1; i < arr.size(); i++) {
        // If the current number is bigger, update our largest value.
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // After checking every element, largest contains the answer.
    return largest;
}

int main() {
    // Example array to test the function.
    vector<int> arr = {3, 8, 2, 10, 5};

    // Print the largest element: expected output is 10.
    cout << largestElement(arr) << endl;

    return 0;
}
