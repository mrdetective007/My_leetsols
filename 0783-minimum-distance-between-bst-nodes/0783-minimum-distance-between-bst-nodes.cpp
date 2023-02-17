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
    vector<int> vec;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            vec.push_back(root->val);
            inorder(root->right);
        }else{
            return;
        }
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int mini=INT_MAX;
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                mini=min(abs(vec[i]-vec[j]),mini);
            }
        }
        return mini;
    }
};