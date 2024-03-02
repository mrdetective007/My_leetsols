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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)
        {
            return false;
        }
        bool even_level=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(even_level)
                {
                    if(i == n-1)
                    {
                        if((curr->val)%2 == 0)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(curr->val >= q.front()->val)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if(i == n-1)
                    {
                        if((curr->val)%2)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(curr->val <= q.front()->val)
                        {
                            return false;
                        }
                    }
                }
                
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
            even_level = !even_level;
        }
        return true;
    }
};