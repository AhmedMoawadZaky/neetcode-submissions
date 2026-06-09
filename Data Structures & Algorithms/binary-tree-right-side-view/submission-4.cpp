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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>result;
        queue<TreeNode *>Q;
        if(root != nullptr)
        {
            Q.push(root);
        }
        while(!Q.empty())
        {
            int length = Q.size();
            TreeNode * cur = Q.front();
            result.push_back(cur->val);
            for(int i = 0 ; i < length ; ++i)
            {
                cur = Q.front();
                Q.pop();
                if(cur->right != nullptr)
                {
                    Q.push(cur->right);
                }
                if(cur->left != nullptr)
                {
                    Q.push(cur->left);
                }
            }
        }
        return result;
    }
};
