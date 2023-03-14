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
    vector<vector<int>> vec;
    void solve(TreeNode* root,vector<int> v){
        if(root){
            v.push_back(root->val);
            if(!root->left&&!root->right){
                vec.push_back(v);
            }
            solve(root->left,v);
            solve(root->right,v);
        }else{
            return;
        }
    }
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        vector<int>ans;
        for(auto x:vec){
            int a=0;
            for(int i=0;i<x.size();i++){
                a*=10;
                a+=x[i];
            }
            ans.push_back(a);
        }
        int sum=0;
        for(auto x:ans){
            sum+=x;
        }
        return sum;
    }
};