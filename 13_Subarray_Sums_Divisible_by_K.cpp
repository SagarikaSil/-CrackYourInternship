// 974. Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of 
// non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0, rem=0, sum=0;
        unordered_map<int,int> map;
        map[0]=1;
        
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum%k>=0) 
                rem=sum%k;
            else
                rem=sum%k+k;
            if(map[rem])
                ans+=map[rem];
            map[rem]++;
        }
        return ans;
    }
};