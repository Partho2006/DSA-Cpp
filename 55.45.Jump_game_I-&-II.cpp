// 55. Jump Game

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;        
    }
};
 
____________________________________________________________________________________________________________________

// 45. Jump Game II

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2

class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    // Implicit BFS
    for (int i = 0; i < nums.size() - 1; ++i) {
      farthest = max(farthest, i + nums[i]);
      if (farthest >= nums.size() - 1) {
        ++ans;
        break;
      }
      if (i == end) {    // Visited all the items on the current level
        ++ans;           // Increment the level
        end = farthest;  // Make the queue size for the next level
      }
    }

    return ans;
  }
};

