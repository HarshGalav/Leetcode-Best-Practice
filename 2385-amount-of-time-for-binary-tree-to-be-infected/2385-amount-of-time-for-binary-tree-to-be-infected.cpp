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
    void convert(TreeNode* root, unordered_map<int,vector<int>>&adj){
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            convert(root->left,adj);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            convert(root->right,adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        convert(root,adj);
        unordered_set<int>vis;
        queue<pair<int,int>>q;
        q.push({start,0});
        int ans=0;
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            vis.insert(a);
            ans=max(ans,b);
            q.pop();
            for(auto i: adj[a]){
                if(vis.find(i)==vis.end()){
                q.push({i,b+1});
                }

            }
        }
        return ans;

    }
};