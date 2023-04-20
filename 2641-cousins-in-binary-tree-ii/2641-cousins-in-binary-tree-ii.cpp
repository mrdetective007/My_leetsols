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
    
    unordered_map<int, int> mp;
    
    void trav(TreeNode* root, int h)
    {
        if(root == NULL)
            return;
        mp[h] = mp[h] + root->val;
        trav(root->left, h + 1);
        trav(root->right, h + 1);
        return;
    }
    
    void dfs(TreeNode* root, int h, int sib)
    {
        if(root == NULL)
            return;
        
        int l=0,r=0;
        
        if(root->right!=nullptr)
            r=root->right->val;
        
        if(root->left!=nullptr)
            l=root->left->val;
        
        root->val = mp[h] - root->val - sib;
        dfs(root->left, h + 1, r);
        dfs(root->right, h + 1, l);
        return;
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        trav(root, 0);
        dfs(root, 0, 0);
        return root;
    }
};