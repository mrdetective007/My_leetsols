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
    int i=0;
    TreeNode* solve(vector<int> &preorder,int bound=INT_MAX){
        if(i>=preorder.size() || preorder[i]>bound){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=solve(preorder,root->val);
        root->right=solve(preorder,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,INT_MAX);
    }
};