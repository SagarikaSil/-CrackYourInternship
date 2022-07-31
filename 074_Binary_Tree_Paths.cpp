// 257. Binary Tree Paths

// Given the root of a binary tree, return all root-to-leaf paths in any order.
// A leaf is a node with no children.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<string> &ans, string res){
        if(root==NULL)
            return;
        
        if(root->left||root->right){
            res+=to_string(root->val)+"->";
        }
        else{
            res+=to_string(root->val);
            ans.push_back(res);
        }
        
        helper(root->left,ans,res);
        helper(root->right,ans,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string res="";
        helper(root,ans,res);
        
        return ans;
    }
};

// class Solution {
// public:
//     void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
//         if(!root->left && !root->right) {
//             result.push_back(t);
//             return;
//         }

//         if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string (root->left->val));
//         if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string (root->right->val));
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> result;
//         if(!root) return result;

//         binaryTreePaths(result, root, to_string(root->val));
//         return result;
//     }
// };