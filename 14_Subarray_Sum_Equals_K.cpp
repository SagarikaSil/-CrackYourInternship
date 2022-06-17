// 560. Subarray Sum Equals K

// Given an array of integers nums and an integer k, return the total number 
// of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans=0,sum=0;
        map[0]=1;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rsum = sum - k;
            if(map[rsum])
                ans += map[rsum];
            map[sum]++;
        }
        return ans;
    }
};