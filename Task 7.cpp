#include <iostream>
using namespace std;

// 1. Recursive helper to check if a subset sum equals target (No loops allowed)
bool checkSubsetSum(int arr[], int n, int target, int skipIndex, int currIndex) {
    if (target == 0) return true; // Target reached
    if (currIndex >= n || target < 0) return false; // Out of bounds or target exceeded

    // Skip the index of the largest number we are testing
    if (currIndex == skipIndex) {
        return checkSubsetSum(arr, n, target, skipIndex, currIndex + 1);
    }

    // Include the element OR exclude the element recursively
    bool include = checkSubsetSum(arr, n, target - arr[currIndex], skipIndex, currIndex + 1);
    bool exclude = checkSubsetSum(arr, n, target, skipIndex, currIndex + 1);

    return include || exclude;
}

// 2. Recursive helper to find the index of the largest number that is less than a specific limit
int getLargestIndex(int arr[], int n, int maxLimit, int currIndex, int bestIndex) {
    if (currIndex == n) return bestIndex;

    // Check if current item is smaller than our previous maximum limit but larger than current best
    if (arr[currIndex] < maxLimit) {
        if (bestIndex == -1 || arr[currIndex] > arr[bestIndex]) {
            bestIndex = currIndex;
        }
    }
    return getLargestIndex(arr, n, maxLimit, currIndex + 1, bestIndex);
}

// 3. Main recursive strategy function for Magic Number
int findMagicNumber(int arr[], int n, int maxLimit) {
    // Get the index of the largest item below our limit
    int largestIdx = getLargestIndex(arr, n, maxLimit, 0, -1);

    // Base Case: If no valid elements are left to check
    if (largestIdx == -1) return -1;

    int largestValue = arr[largestIdx];

    // Check if subset sum of remaining elements matches this value
    if (checkSubsetSum(arr, n, largestValue, largestIdx, 0)) {
        return largestValue; // Success: Found the magic number
    }

    // Otherwise, repeat the process with the next largest number
    return findMagicNumber(arr, n, largestValue);
}

int main() {
    // Sample test array from instructions
    int arr[] = { 2, 3, 5, 8, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "--- Task 7: Magic Number (Bonus) ---" << endl;

    // Passing a very high dummy value initially as maxLimit to capture the absolute maximum first
    int magicNumber = findMagicNumber(arr, n, 999999);

    cout << "Output: " << magicNumber << endl;

    return 0;
}