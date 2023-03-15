class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool nullBeforeNode = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(size(q))
        {
            auto node = q.front();
            q.pop();
            
            if(node == NULL) nullBeforeNode = true;
            else 
            {
                if(nullBeforeNode == true) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};