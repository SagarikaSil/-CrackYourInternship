// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution {
public:
    void helper(vector<string> &v, int n, string ans, int open, int close){
        if(ans.size()==2*n){
            v.push_back(ans);
            return;
        }
        if(open<n)
            helper(v,n,ans+'(',open+1,close);
        if(close<open)
            helper(v,n,ans+')',open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        helper(v,n,"",0,0);
        return v;
    }
};