// 442. Find All Duplicates in an Array

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Method1
// Time=O(n), space=O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;    
        for(int i=0; i<nums.size(); i++){
            int index=abs(nums[i])-1;
            if(nums[index]<0)
                ans.push_back(index+1);
            nums[index]=-nums[index];
        }
        return ans;
    }
};

// Method2
// Space=Time=O(n);
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;    
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]])
                ans.push_back(nums[i]);
            map[nums[i]]++;
        }
        return ans;
    }
};

// Method3
// Time=O(nlogn), space=O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()<=1)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};