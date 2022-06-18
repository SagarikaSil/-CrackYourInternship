// 9. Palindrome Number

// Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward.
// For example, 121 is a palindrome while 123 is not.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        int z=x; long ans=0;
    
        while(x!=0){
            int r=x%10;
            ans=ans*10+r;
            x/=10;
        }
        if(z==ans){
            return true;
        }
        else return false;
    }
};

