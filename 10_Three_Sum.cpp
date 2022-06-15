// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0||nums[i]!=nums[i-1]){
                int j=i+1, k=nums.size()-1;
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        while(j<k&&nums[j]==nums[j+1]) j++;
                        while(j<k&&nums[k]==nums[k-1]) k--;
                        j++; k--;
                    }
                    else if(sum>0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return ans;
    }
};
