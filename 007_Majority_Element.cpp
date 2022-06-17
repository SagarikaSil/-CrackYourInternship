// 169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Follow-up: Could you solve the problem in linear time and in O(1) space?

// method1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0,c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[majority]==nums[i])
                c++;
            else 
                c--;
            if(c==0){
                majority=i;
                c=1;
            }
        }
        return nums[majority];
    }
};

// method2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};