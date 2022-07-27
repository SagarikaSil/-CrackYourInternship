// 71. Simplify Path

// Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
// In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
// The canonical path should have the following format:
// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
// Return the simplified canonical path.

class Solution {
public:
    string simplifyPath(string path) {
        string res="";
        int ind=path.size()-1;
        int back=0;
        
        while(ind>=0){
            string temp="";
            while(ind>=0&&path[ind]!='/'){
                temp+=path[ind];
                ind--;
            }
            ind--;
            if(temp=="."||temp=="")
                continue;
            
            if(temp=="..")
                back++;
            else if(back>0)
                back--;
            else{
                res+=temp;
                res+="/";
            }
        }
        reverse(res.begin(),res.end());
        if(res=="")
            return "/";
        return res;
    }
};
