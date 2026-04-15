// 74. Search a 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = row * col - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int element = matrix[mid / col][mid % col];

            if (element == target) {
                return true;
            }
            if (element < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }
};

// Time complexity: O(log(m * n))
// Space complexity: O(1)