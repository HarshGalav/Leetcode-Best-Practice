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
class FindElements {
public:
unordered_set<int>mp;
void f(TreeNode* root,int value){
    queue<TreeNode*>q;
    q.push(root);
    root->val=value;
    
    while(!q.empty()){
        TreeNode* temp=q.front();
        mp.insert(temp->val);
        q.pop();
        if(temp->left){
            q.push(temp->left);
            temp->left->val=(2*temp->val)+1;
        }
        if(temp->right){
            q.push(temp->right);
            temp->right->val=(2*temp->val)+2;
        }
    }

}
    FindElements(TreeNode* root) {
       f(root,0);
    }
    
    bool find(int target) {
        if(mp.count(target)){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */