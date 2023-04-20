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
    
    TreeNode* dfs(TreeNode* root,int low,int high){
        if(root==nullptr){
            return root;
        }
        if(root->val<low){
            root=dfs(root->right,low,high);
            return root;
        }
        // if(root->val>high){
        //     root=dfs(root->left,low,high);
        // }
        if(root->val>=low && root->val<=high){
            root->left=dfs(root->left,low,high);
            root->right=dfs(root->right,low,high);
            return root;
        }
        return dfs(root->left,low,high);
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* head=dfs(root,low,high);
        return head;
    }
};