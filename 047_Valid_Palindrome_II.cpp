// 680. Valid Palindrome II

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

class Solution {
    public:
    bool isPal(string str, int i, int j){
        while(i<j){
            if(str[i]!=str[j])
            return false;
                i++;
                j--;
        }
            return true;
    }
    bool validPalindrome(string s)
    {
      int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return (isPal(s,i+1,j)||isPal(s,i,j-1));
            i++;
            j--;
        }
        return true;
    }
};