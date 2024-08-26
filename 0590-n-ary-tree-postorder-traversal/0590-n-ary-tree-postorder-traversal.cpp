/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    void ok(Node* root){
        if(root!=nullptr){
            for(auto x:root->children){
                ok(x);
                res.push_back(x->val);
            }
        }
        else{
            return;
        }
    }
    
    
    vector<int> postorder(Node* root) {
        if(root==nullptr){
            return {};
        }
        ok(root);
        res.push_back(root->val);
        return res;
    }
};