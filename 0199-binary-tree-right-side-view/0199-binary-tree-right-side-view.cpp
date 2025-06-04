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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        f(root,0,res);
        return res;
    }
    void f(TreeNode* root,int l,vector<int>&res){
        if(root==NULL)return;
        if(l==res.size())res.push_back(root->val);
        f(root->right,l+1,res);
        f(root->left,l+1,res);
    }
};