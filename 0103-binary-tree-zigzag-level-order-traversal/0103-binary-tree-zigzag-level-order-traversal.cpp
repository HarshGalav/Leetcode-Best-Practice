class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> v(n);

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int idx = leftToRight ? i : (n - i - 1);
                v[idx] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            result.push_back(v);
            leftToRight = !leftToRight;
        }
        return result;
    }
};
