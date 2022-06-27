// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Method1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])
                ans+=a[i];
            else
                break;
        }
        return ans;
    }
};

// Method2
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minword=strs[0].size(); //the output string's length will be equal to                                       minimum length of word
        int n=strs.size();         //in given inout string
    
        for(int i=1;i<n;i++){  //updating minword length
            if(strs[i].size() < minword){
                minword=strs[i].size();
            }
        }
        string ans; //output ans
        char ch; 
    
        for(int i=0;i<minword;i++){
            ch = strs[0][i];  //first character of strs[0][i] 
            for(int j=1;j<n;j++){       //comparing first character with first                                                  character of all words  
                if(strs[j][i]!=ch){ //if at any point it doesn't match
                    return ans;    //return ans
                }
            }
            ans+=ch; //else add hte current character to the output string
        }
    return ans;
    }
};