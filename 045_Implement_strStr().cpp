// 28. Implement strStr()

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

// Method1
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// Method2
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        int j=0;
        for(int i=0;i<haystack.length();i++){
            int temp = i;  
            while(j<needle.length() && haystack[i]==needle[j]){
               j++, i++;
            }
          
            if(j==needle.length()){
               return temp;
            }
            else{
               i = temp, j = 0;
            }
        }
        return -1;
    }
};