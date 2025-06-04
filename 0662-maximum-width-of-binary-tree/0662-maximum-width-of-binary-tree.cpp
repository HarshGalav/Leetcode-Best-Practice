class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxi=INT_MIN;
        while (!q.empty()) {
            int n=q.size();
            int l=q.front().second;
            int r=q.back().second;
            maxi=max(maxi,r-l+1);
            while(n--){
                auto [a,b]=q.front();
                q.pop();
                if(a->left!=NULL){
                    q.push({a->left,2*b+1});
                }
                if(a->right!=NULL){
                    q.push({a->right,2*b+2});
                }
            }

        }

        return maxi;
    }
};
