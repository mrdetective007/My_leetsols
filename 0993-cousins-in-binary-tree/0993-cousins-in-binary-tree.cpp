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
    
    map<int,pair<int,int>> m;
    void dfs(TreeNode* root,int pare,int h){
        if(root!=NULL){
            m[root->val]={pare,h};
            h++;
            dfs(root->left,root->val,h);
            dfs(root->right,root->val,h);
        }else{
            return;
        }
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,-1,0);
        if(m[x].first!=m[y].first && m[x].second==m[y].second){
            return true;
        }
        return false;
    }
};