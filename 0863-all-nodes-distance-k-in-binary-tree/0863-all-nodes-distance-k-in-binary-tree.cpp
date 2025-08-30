/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void convert(TreeNode* root, unordered_map<int,vector<int>>&adj){
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            convert(root->left,adj);
        }
        if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            convert(root->right,adj);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>adj;
        convert(root,adj);
        queue<pair<int,int>>q;
        q.push({target->val,0});
        vector<int>ans;
        unordered_set<int>visited;
        while(!q.empty()){
            int a= q.front().first;
            int b=q.front().second;
            if(visited.count(a)){
                continue;
            }
            visited.insert(a);
            if(b==k){
                ans.push_back(a);
            }
            q.pop();
            for(auto i: adj[a]){
                if(visited.find(i)==visited.end()){
                q.push({i,b+1});
                }
            }
        }
        return ans;
    }
};