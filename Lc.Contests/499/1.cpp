// Q1. Valid Elements in an Array

// You are given an integer array nums.

// An element nums[i] is considered valid if it satisfies at least one of the following conditions:

// It is strictly greater than every element to its left.
// It is strictly greater than every element to its right.
// The first and last elements are always valid.

// Return an array of all valid elements in the same order as they appear in nums.

// Example 1:
// Input: nums = [1,2,4,2,3,2]
// Output: [1,2,4,3,2]
// Explanation:
// nums[0] and nums[5] are always valid.
// nums[1] and nums[2] are strictly greater than every element to their left.
// nums[4] is strictly greater than every element to its right.
// Thus, the answer is [1, 2, 4, 3, 2].
// Example 2:
// Input: nums = [5,5,5,5]
// Output: [5,5]

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        vector<int> leftMax(n), rightMax(n);

        // build left max
        leftMax[0] = nums[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], nums[i]);
        }

        // build right max
        rightMax[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        // check valid elements
        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n-1 ||
               nums[i] > leftMax[i-1] ||
               nums[i] > rightMax[i+1]) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};

