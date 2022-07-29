// 844. Backspace String Compare

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

// Stack
class Solution {
public:
    void helper(stack<int> &stack, string str, int n){
        for(int i=0; i<n; i++){
            while(str[i]!='#'&&i<n){
                stack.push(str[i]);
                i++;
            }
            if(str[i]=='#'){
                if(!stack.empty())
                    stack.pop();
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        stack<int> first;
        stack<int> second;
        
        helper(first,s,s.size());
        helper(second,t,t.size());
        
        if(first.size()!=second.size())
            return false;
        
        while(!first.empty()&&!second.empty()){
            char f=first.top();
            char s=second.top();
            if(f!=s)
                return false;
            first.pop();
            second.pop();
        }
        return true;
    }
};

// Iterative
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         int k=0,p=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='#'){
//                 k--;
//                 k=max(0,k);
//             }
//            else{
//                s[k]=s[i];
//                k++;
//            }
//         }
//         for(int i=0;i<t.size();i++){
//             if(t[i]=='#'){
//                 p--;
//                 p=max(0,p);
//             }
//            else{
//                t[p]=t[i];
//                p++;
//            }
//         }
//         if(k!=p)
//             return false;
//         else{
//             for(int i=0;i<k;i++){
//                 if(s[i]!=t[i])
//                     return false;
//             }
//             return true;
//         }
//     }
// };