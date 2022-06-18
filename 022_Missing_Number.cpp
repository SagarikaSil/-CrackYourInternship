// 268. Missing Number

// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

// Method1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans=ans^nums[i]^(i+1);
        }
        return ans;
    }
};

// Method2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total=0, n=nums.size();
        for(int i=0; i<n; i++){
             total+=nums[i];
         }
        cout<<total;
        int sum=((n)*(n+1))/2;
        return sum-total;
    }
};

// Method3
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> ans; 
        for(int i=0; i<nums.size(); i++){
            ans.insert(nums[i]);
        }
        int i=0;
        for(i=0; i<nums.size(); i++){
            if(ans.find(i)==ans.end()){
                return i;
            }
        }   
        return i;
    }
};