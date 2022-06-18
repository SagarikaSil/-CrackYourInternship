// 202. Happy Number

// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// 1.Starting with any positive integer, replace the number by the sum of the squares of its digits.
// 2.Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// 3.Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Method1
class Solution {
public:
    int squareSum(int n){
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+=r*r;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n<=0)
            return false;
        unordered_set<int> ans;
        while(ans.find(n)==ans.end()){
            ans.insert(n);
            n=squareSum(n);
            if(n==1)
                return true;
        }
        return false;
    }
};

// method 2
class Solution {
public:
    int squareSum(int n){
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+=r*r;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n<=0)
            return false;
        int slow=n;
        int fast=squareSum(n);
        if(slow==1||fast==1)
            return true;
        
        while(slow!=fast){
            slow=squareSum(slow);
            fast=squareSum(squareSum(fast));
            if(slow==1||fast==1)
                return true;
        }
        return false;
    }
};