// 628. Maximum Product of Three Numbers

// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        int product=1;
        
        for(int i=0; i< 3; i++){
            product*=nums[i];
        }
        
        return max(product, nums[0]*nums[n-1]*nums[n-2]); 
    }
};