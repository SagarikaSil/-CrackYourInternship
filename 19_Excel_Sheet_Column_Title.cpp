// 168. Excel Sheet Column Title

// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "", res = "";
       while(columnNumber > 0){
           columnNumber--;
           char letter = columnNumber % 26 + 'A';
           ans += letter;
           columnNumber /= 26;
       }
        for(int i = ans.length() - 1; i >= 0; i--)
            res += ans[i];
        
        return res;
    }
};