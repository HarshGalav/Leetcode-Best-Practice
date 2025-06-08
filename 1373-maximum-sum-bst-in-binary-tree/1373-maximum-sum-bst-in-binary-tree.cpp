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
    int ans=0;
    vector<int>dfs(TreeNode* root){
        if(!root)
            return {INT_MAX,INT_MIN,0};
        vector<int>L=dfs(root->left);
        vector<int>R=dfs(root->right);
        int v=root->val;
        if(L[1]<v && v<R[0]){
            int sum=L[2]+R[2]+v;
            ans=max(ans,sum);
            return {min(v,L[0]),max(v,R[1]),sum};
        }
        else{
            return {INT_MIN,INT_MAX,0};
        }
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};