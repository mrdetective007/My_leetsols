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
    
    map<TreeNode*,int> m;
    void traverse(TreeNode* root,vector<int> &ans){
        if(root!=NULL){
            bool prev=true;
            int ans1=dfs(root->left,true);
            prev=false;
            int ans2=dfs(root->right,false);
            ans.push_back(max(ans1,ans2));
            traverse(root->left,ans);
            traverse(root->right,ans);
        }else{
            return;
        }
    }
    
    int dfs(TreeNode* root,bool prev){
        if(root==NULL){
            return 0;
        }
        if(m[root]!=0){
            return m[root];
        }
        int maxi=1;
        if(prev){
            prev=false;
            maxi=1+dfs(root->right,prev);
            // return m[root]=maxi;
        }else{
            prev=true;
            maxi=1+dfs(root->left,prev);
            // return m[root]=maxi;
        }
        return m[root]=maxi;
    }
    
    int longestZigZag(TreeNode* root) {
        vector<int> ans;
        traverse(root,ans);
        return *max_element(ans.begin(),ans.end());
    }
};