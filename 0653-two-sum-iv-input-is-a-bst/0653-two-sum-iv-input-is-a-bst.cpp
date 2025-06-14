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
    void f(TreeNode* root, vector<int>&v){
        if(root==NULL){
            return;
        }
        f(root->left,v);
        v.push_back(root->val);
        f(root->right,v);
    }
    bool bs(vector<int>v,int k){
        int l=0,r=v.size()-1;
        while(l<r){
           int sum=v[l]+v[r];
           if(sum==k){
            return true;
           }
           else if(sum>k){
            r--;
           }
           else{
            l++;
           }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        f(root,v);
        return bs(v,k);
    }
};