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
    
    map<int,vector<TreeNode*>> m;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> vec;
        if(n<1 || n%2==0){
            return vec;
        }
        if(n==1){
            TreeNode* root=new TreeNode(0);
            vec.push_back(root);
            m[1]=vec;
            return vec;
        }
        if(m.find(n)!=m.end()){
            return m[n];
        }
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> lefty=allPossibleFBT(i);
            vector<TreeNode*> righty=allPossibleFBT(n-i-1);
            for(int j=0;j<lefty.size();j++){
                for(int k=0;k<righty.size();k++){
                    TreeNode* root=new TreeNode(0);
                    root->left=lefty[j];
                    root->right=righty[k];
                    vec.push_back(root);
                }
            }
        }
        m[n]=vec;
        return vec;
    }
};