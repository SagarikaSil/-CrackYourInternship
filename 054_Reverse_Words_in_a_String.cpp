// 151. Reverse Words in a String

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

class Solution {
public:
    void reverse(string &s, int i, int j){
        while(i<j){
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++; j--;
        }
    }
    string reverseWords(string s) {
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(i<len){
            while(i<len && s[i] == ' ') 
                i++;  
            if(i==len) 
                break;
            if(wordcount) 
                s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {
                s[j]=s[i]; j++; i++;
            } 
            reverse(s,l,j-1);                
            wordcount++;   
        }
        s.resize(j);                           
        reverse(s,0,j-1);         
        return s;
    }
};
