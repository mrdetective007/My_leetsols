/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "|";
        }
        string ans=to_string(root->val)+"|"+serialize(root->left)+serialize(root->right);
        return ans;
    }
    TreeNode* construct(stringstream &ss){
        string temp;
        getline(ss,temp,'|');
        if(temp==""){
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=construct(ss);
        root->right=construct(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode* root=construct(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;