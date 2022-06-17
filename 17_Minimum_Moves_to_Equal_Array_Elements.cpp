// 453. Minimum Moves to Equal Array Elements

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// In one move, you can increment n - 1 elements of the array by 1.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total=0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            total+=nums[i]-nums[0];
        }
        return total;
    }
};