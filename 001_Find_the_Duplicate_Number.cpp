// 287. Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=1,right=n-1,c,mid;

        while(left<right)
        {
            mid=(left+right)/2;
            c=0;

            for(int i=0;i<n;i++)
                if(nums[i]<=mid)c++;

            if(c>mid)right=mid;
            else left=mid+1;
        }
        return left;
    }
};