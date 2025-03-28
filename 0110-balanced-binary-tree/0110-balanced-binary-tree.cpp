/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(()int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int rh=dfs(root->right);
        if(rh==-1) return -1;
        int lh=dfs(root->left);
        if(lh==-1) return -1;
        if(abs(rh-lh)>1) return -1;

        return 1+max(rh,lh);
    }
};