// 442. Find All Duplicates in an Array

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};

// Time Complexcity - O(N)
// Space Complexcity - O(1)

// # 🧠 Full code breakdown

// ```cpp
// vector<int> findDuplicates(vector<int>& nums)
// ```

// * Function returns a vector of duplicate numbers
// * `nums` is passed by reference (so we can modify it)

// ---

// ```cpp
// if(nums.empty()) return {};
// ```

// * Edge case: if array is empty → return empty vector

// ---

// ```cpp
// vector<int> ans;
// ```

// * Stores duplicates

// ---

// ```cpp
// for(int i = 0; i < nums.size(); i++)
// ```

// * Loop through array

// ---

// ## 🔥 CORE LOGIC (MOST IMPORTANT)

// ```cpp
// if(nums[abs(nums[i]) - 1] < 0)
// ```

// ### What this means:

// * `abs(nums[i])` → get original value (ignore sign)
// * `-1` → convert value to index (1-based → 0-based)

// 👉 So:

// ```cpp
// value = nums[i]
// index = value - 1
// ```

// ---

// ### Why check `< 0`?

// * If already negative → we’ve visited this number before
//   👉 means it's a **duplicate**

// ---

// ```cpp
// ans.push_back(abs(nums[i]));
// ```

// * Add duplicate to answer

// ---

// ```cpp
// nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
// ```

// ### This is the marking step:

// * Go to index `(value - 1)`
// * Make that number negative

// 👉 Meaning:

// > “I have seen this number”

// ---

// # 🧠 Example walkthrough

// ```cpp
// nums = [4,3,2,7,8,2,3,1]
// ```

// ### Step-by-step idea:

// | i | nums[i] | index | action                       |
// | - | ------- | ----- | ---------------------------- |
// | 0 | 4       | 3     | mark nums[3] negative        |
// | 1 | 3       | 2     | mark nums[2] negative        |
// | 2 | 2       | 1     | mark nums[1] negative        |
// | 3 | 7       | 6     | mark nums[6] negative        |
// | 4 | 8       | 7     | mark nums[7] negative        |
// | 5 | 2       | 1     | already negative → duplicate |
// | 6 | 3       | 2     | already negative → duplicate |

// 👉 Output:

// ```cpp
// [2, 3]
// ```

// ---

// # ⚡ Key concept (must remember)

// 👉 **Index marking using negative sign**

// * First visit → mark negative
// * Second visit → already negative → duplicate

// ---

// # ⚠️ Important conditions

// This ONLY works if:

// * Values are in range `1 to n`
// * You’re allowed to modify array
