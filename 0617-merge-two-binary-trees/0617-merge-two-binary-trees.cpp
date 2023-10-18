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
    
    TreeNode* ok(TreeNode* r1,TreeNode* r2){
        if(!r1 && !r2){
            return nullptr;
        }
        if(!r1){
            return r2;
        }
        if(!r2){
            return r1;
        }
        r1->val+=r2->val;
        r1->left=ok(r1->left,r2->left);
        r1->right=ok(r1->right,r2->right);
        return r1;
    }
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return ok(root1,root2);
    }
};