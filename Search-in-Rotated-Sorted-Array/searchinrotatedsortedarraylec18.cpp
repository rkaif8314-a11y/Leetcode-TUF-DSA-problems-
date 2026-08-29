#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Search in Rotated Sorted Array - Lecture 18/144
// ============================================================
//
// Problem:
// Given a sorted array that has been rotated, find the index
// of the target element.
//
// Example:
// Original sorted array:
// [0, 1, 2, 3, 4, 5, 6]
//
// Rotated array:
// [4, 5, 6, 0, 1, 2, 3]
//
// Target = 2
//
// Answer = index 5
//
// ------------------------------------------------------------
// Linear Search:
// We can simply check every element one by one.
//
// Time Complexity: O(n)
//
// But we can do better using Binary Search.
// ------------------------------------------------------------
//
// Optimized approach:
// Binary Search
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ============================================================


class Solution {
public:

    int search(vector<int>& A, int tar) {

        // 'st' points to the beginning of the current
        // search range.
        int st = 0;

        // 'end' points to the end of the current
        // search range.
        int end = A.size() - 1;


        // Continue while there is a valid search range.
        while (st <= end) {

            // Calculate middle safely to avoid integer overflow.
            int mid = st + (end - st) / 2;


            // ------------------------------------------------
            // CASE 1: TARGET FOUND
            // ------------------------------------------------

            if (A[mid] == tar) {
                return mid;
            }


            // ------------------------------------------------
            // CASE 2: LEFT HALF IS SORTED
            // ------------------------------------------------
            //
            // If A[st] <= A[mid], the left portion is sorted.
            //
            // Example:
            // [4, 5, 6, 0, 1, 2, 3]
            //  st     mid
            //
            // Left half = [4, 5, 6]
            // ------------------------------------------------

            if (A[st] <= A[mid]) {

                // Check whether target lies inside the
                // sorted left half.

                if (A[st] <= tar && tar <= A[mid]) {

                    // Target is in the left half.
                    // Eliminate the right half.

                    end = mid - 1;

                } else {

                    // Target is NOT in the left half.
                    // Search the right half.

                    st = mid + 1;
                }

            }


            // ------------------------------------------------
            // CASE 3: RIGHT HALF IS SORTED
            // ------------------------------------------------
            //
            // If the left half is not sorted, the right half
            // must be sorted.
            //
            // Example:
            // [6, 0, 1, 2, 3, 4, 5]
            //     mid        end
            //
            // Right half = [1, 2, 3, 4, 5]
            // ------------------------------------------------

            else {

                // Check whether target lies inside the
                // sorted right half.

                if (A[mid] <= tar && tar <= A[end]) {

                    // Target is in the right half.
                    // Eliminate the left half.

                    st = mid + 1;

                } else {

                    // Target is NOT in the right half.
                    // Search the left half.

                    end = mid - 1;
                }
            }
        }


        // Search range became empty.
        // Target does not exist in the array.

        return -1;
    }
};


// ============================================================
// IMPORTANT IDEA
// ============================================================
//
// In a rotated sorted array, at least ONE of the two halves
// around 'mid' will always be sorted.
//
// We determine:
//
// 1. Is the LEFT half sorted?
//       A[st] <= A[mid]
//
// 2. Otherwise, RIGHT half is sorted.
//
// Then we check whether the target belongs to that sorted half.
//
// If yes:
//     Search that half.
//
// If no:
//     Search the other half.
//
// ============================================================


// ============================================================
// EXAMPLE: [4, 5, 6, 7, 0, 1, 2], target = 0
// ============================================================
//
// st = 0, end = 6
// mid = 3
// A[mid] = 7
//
// Left half [4,5,6,7] is sorted.
//
// Target 0 is NOT between 4 and 7.
//
// Therefore search right half.
//
// st = mid + 1
// st = 4
//
// Now search:
//
// [0,1,2]
//
// mid = 5
// A[mid] = 1
//
// Right half [1,2] is sorted.
//
// Target 0 is NOT in [1,2].
//
// Search left.
//
// end = mid - 1
// end = 4
//
// Now:
//
// mid = 4
// A[mid] = 0
//
// Target found.
//
// return 4
// ============================================================


// ============================================================
// COMPLEXITY
// ============================================================
//
// Linear Search:
// Time  = O(n)
// Space = O(1)
//
// Rotated Binary Search:
// Time  = O(log n)
// Space = O(1)
//
// Binary Search is faster because approximately half of the
// search space is removed during every iteration.
// ============================================================
