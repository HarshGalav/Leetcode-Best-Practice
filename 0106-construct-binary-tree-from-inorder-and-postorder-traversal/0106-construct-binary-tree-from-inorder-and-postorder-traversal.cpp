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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return nullptr;
        }
        int n=inorder.size();
        map<int,int>inmap;
        for(int i=0;i<n;i++){
            inmap[inorder[i]]=i;
        }
        return f(inorder,0,n-1,postorder,0,postorder.size()-1,inmap);
    }
    TreeNode* f(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,map<int,int>&inmap){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=inmap[postorder[pe]];
        int numsleft=inroot-is;

        root->left=f(inorder,is,inroot-1,postorder,ps,ps+numsleft-1,inmap);
        root->right=f(inorder,inroot+1,ie,postorder,ps+numsleft,pe-1,inmap);
        return root;

    }
};