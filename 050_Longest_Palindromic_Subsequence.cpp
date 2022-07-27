// 516. Longest Palindromic Subsequence

// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting 
// some or no elements without changing the order of the remaining elements.

class Solution {
public:

//RECURSION
//TC= exponential
//SC=O(N+M)

int recursion(int i, int j, string &s,string &t)
{
    if(i<0||j<0)return 0;
        if(s[i]==t[j])return 1+recursion(i-1,j-1,s,t);
    return max(recursion(i-1,j,s,t),recursion(i,j-1,s,t));
}

//MEMOIZATION
//TC=O(N*M)
//SC=O(N*M)+O(N+M)

int memo(int i,int j,string &s,string &t,vector<vector<int>> &dp)
{
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=1+memo(i-1,j-1,s,t,dp);
    return dp[i][j]=max(memo(i-1,j,s,t,dp),memo(i,j-1,s,t,dp));
}

//TABULATION
//TC=O(N*M)
//SC=O(N*M)

int tabulation(int n,int m,string &s,string &t, vector<vector<int>> &dp)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i]==t[j])
            {
                if(i==0||j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                int left=0,right=0;
                if(i>0)left=dp[i-1][j];
                if(j>0)right=dp[i][j-1];
                dp[i][j]=max(left,right);
            }
        }
    }
    return dp[n-1][m-1];
}

//SPACE OPTIMIZATION
//TC=O(N*M)
//SC=O(M)

int space_optimization(int n,int m, string &s,string &t)
{
    vector<int> prev(m,0),curi(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i]==t[j])
            {
                if(i==0||j==0)
                    curi[j]=1;
                else
                    curi[j]=1+prev[j-1];
            }
            else
            {
                int left=0,right=0;
                if(i>0)left=prev[j];
                if(j>0)right=curi[j-1];
                curi[j]=max(left,right);
            }
        }
        prev=curi;
    }
    return prev[m-1];
}

int longestPalindromeSubseq(string s) {
    int n=s.size();
    string t=s;
    int m=n;
    reverse(t.begin(),t.end());
    
    //return recursion(n-1,m-1,s,t);
    
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return memo(n-1,m-1,s,t,dp);
    
    // vector<vector<int>> dp(n,vector<int>(m,0));
    // return tabulation(n,m,s,t,dp);
    
    return space_optimization(n,m,s,t);
}
};