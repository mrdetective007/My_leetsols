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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res=0;
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN,mini=INT_MAX;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().first;
                int dist=q.front().second;
                q.pop();
                maxi=max(maxi,dist);
                mini=min(mini,dist);
                if(curr->left!=nullptr){
                    q.push({curr->left,(long long)2*dist+1});   
                }
                if(curr->right!=nullptr){
                    q.push({curr->right,(long long)2*dist+2});   
                }
            }
            res=max(res,maxi-mini+1);
        }
        return res;
    }
};