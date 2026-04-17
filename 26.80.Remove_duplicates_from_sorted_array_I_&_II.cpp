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
