// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

class Solution {
public:
    // bool isValid(string s) {
    //     int n=(int)s.size();
    //     int top=-1;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(top<0)
    //         {
    //             s[++top]=s[i];
    //             if(s[i]==')' || s[i]=='}' || s[i]==']') 
    //                 return false;
    //         }
    //         else if(s[top]=='(' && s[i]==')')
    //         {
    //             top--;
    //         }
    //         else if(s[top]=='{' && s[i]=='}')
    //         {
    //             top--;
    //         }
    //         else if(s[top]=='[' && s[i]==']')
    //         {
    //             top--;
    //         }
    //         else if(s[i]=='(' || s[i]=='{' || s[i]=='[')
    //         {
    //             s[++top]=s[i];
    //         }
    //         else 
    //             return false;
    //     }
    //     return top<0;
    // }
    bool isValid(string s) {
        if (s.length() %2!=0) 
            return false;
        stack<char> stack;
        for (char ch: s)     //for (int i=0;s[i]!='\0';i++)
        {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            if (ch == ')' || ch == '}' || ch == ']')
            {
                if (stack.empty()) {
                    return false;
                }
                char top = stack.top();
                stack.pop();
                if ((top == '(' && ch != ')') || (top == '{' && ch != '}') || 
                    (top == '[' && ch != ']')) {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};