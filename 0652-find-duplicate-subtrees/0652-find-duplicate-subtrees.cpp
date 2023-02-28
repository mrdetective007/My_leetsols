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
    map<string,vector<TreeNode*>> mp;
    string traverse(TreeNode* root){
        if(!root){
            return "";
        }
        string ans='('+traverse(root->left)+to_string(root->val)+traverse(root->right)+')';
        mp[ans].push_back(root);
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        traverse(root);
        for(auto x:mp){
            if(x.second.size()>1){
                res.push_back(x.second[0]);
            }
        }
        return res;
    }
};