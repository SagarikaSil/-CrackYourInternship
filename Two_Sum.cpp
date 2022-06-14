// 1. Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> result;
        int i;
        for(i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            if(hash.find(complement)!=hash.end())
            {
                result.push_back(hash[complement]);
                result.push_back(i);
                return result;
            }
            else
                hash[nums[i]] = i;
        }     
        return result;
    }
};
