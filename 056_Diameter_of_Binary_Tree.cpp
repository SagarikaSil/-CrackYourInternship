// 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
};

// pair method
// class Solution {
// public:
//     pair<int,int> helper(TreeNode* root){
//         if(root==NULL){
//             pair<int,int> ans;
//             ans.first=0;
//             ans.second=0;
//             return ans;
//         }
        
//         pair<int,int> lans=helper(root->left);
//         pair<int,int> rans=helper(root->right);
        
//         int ld=lans.first;
//         int rd=rans.first;
//         int lh=lans.second;
//         int rh=rans.second;
        
//         pair<int,int> ans;
//         ans.first=max(rh+lh,max(ld,rd));
//         ans.second=1+max(lh,rh);
//         return ans;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         return helper(root).first;
//     }
// };