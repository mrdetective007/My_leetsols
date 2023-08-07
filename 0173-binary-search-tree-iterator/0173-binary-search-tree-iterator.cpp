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

int i=0,j=0,n=1e5;
int vec[100005];
class BSTIterator {
public:
    void in(TreeNode* root){
        if(root!=nullptr){
            in(root->left);
            vec[i]=root->val;
            i++;
            in(root->right);
            return;
        }
        else{
            return;
        }
    }
    
    BSTIterator(TreeNode* root) {
        in(root);
    }
    
    int next() {
        return vec[j++];
    }
    
    bool hasNext() {
        return j<i;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */