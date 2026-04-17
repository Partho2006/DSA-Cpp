// 26. Remove Duplicates from Sorted array

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int index=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != nums[index-1]){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150

// 80. Remove Duplicates from Sorted Array II

// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;

        if (nums.size() <= 2) return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;       
    }
};  