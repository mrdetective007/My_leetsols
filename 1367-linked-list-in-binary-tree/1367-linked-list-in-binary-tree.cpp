/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<string> vec;
    void paths(TreeNode* root, string s){
        if(root == NULL){
            return;
        }
        s+=to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            vec.push_back(s);
        }
        paths(root->left,s);
        paths(root->right,s);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        string s = "";
        paths(root,s);
        ListNode* temp = head;
        string a = "";
        while(temp!=NULL){
            a+=to_string(temp->val);
            temp = temp->next;
        }
        for(auto x:vec){
            if(x.find(a) != std::string::npos){
                return true;
            }
        }
        return false;
    }
};