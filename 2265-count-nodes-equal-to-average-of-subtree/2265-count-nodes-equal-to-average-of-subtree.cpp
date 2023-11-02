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
    int cnt=0;
    pair<int,int> ok(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        auto l=ok(root->left);
        auto r=ok(root->right);
        int sum=root->val+l.first+r.first;
        int n=1+l.second+r.second;
        if((sum/n)==root->val){
            cnt++;
        }
        return {sum,n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        ok(root);
        return cnt;
    }
};