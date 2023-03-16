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
    
    TreeNode* solve(vector<int>&ino,vector<int>&pre,int si,int ei,int &idx){
        if(si>ei){
            return nullptr;
        }
        TreeNode* root=new TreeNode(pre[idx++]);
        int pos=find(ino.begin(),ino.end(),root->val)-ino.begin();
        root->left=solve(ino,pre,si,pos-1,idx);
        root->right=solve(ino,pre,pos+1,ei,idx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int idx=0;
        return solve(inorder,preorder,0,n-1,idx);
    }
};