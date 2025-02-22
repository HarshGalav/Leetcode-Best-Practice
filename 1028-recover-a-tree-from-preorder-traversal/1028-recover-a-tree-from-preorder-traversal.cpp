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
int n;

    TreeNode* f(string traversal, int &i,int depth){
        int j=i;
        if(j>=n){
            return NULL;
        }
        while(j<n && traversal[j]=='-'){
            j++;
        }
        int dash=j-i;
        if(dash!=depth){
            return NULL;
        }
        i+=dash;
        int num=0;
        while(i<n && isdigit(traversal[i])){
            num=(num*10)+(traversal[i]-'0');
            i++;
        }
        TreeNode* root = new TreeNode(num);
        root->left=f(traversal,i,depth+1);
        root->right=f(traversal,i,depth+1);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n=traversal.size();
        int i=0;
        int depth=0;
        return f(traversal,i,depth);
    }
};