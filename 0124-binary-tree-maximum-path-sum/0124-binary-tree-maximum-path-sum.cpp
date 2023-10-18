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
    
    int sum=INT_MIN;
    int ok(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l=max(0,ok(root->left));
        int r=max(0,ok(root->right));
        sum=max(sum,l+r+root->val);
        return max(l,r)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int val=ok(root);
        return sum;
    }
};