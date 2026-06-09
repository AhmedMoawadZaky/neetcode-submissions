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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        queue<TreeNode *>Q;
        TreeNode * cur = nullptr;
        int level = 0 , length = 0;
        if(root != nullptr)
        {
            Q.push(root);
            while(!Q.empty())
            {
                result.push_back(vector<int>());
                length = Q.size();
                for(int i = 0 ; i < length ; ++i)
                {
                    cur = Q.front();
                    Q.pop();
                    result[level].push_back(cur->val);
                    if(cur->left != nullptr)
                    {
                        Q.push(cur->left);
                    }
                    if(cur->right != nullptr)
                    {
                        Q.push(cur->right);
                    }
                }
                level++;
            }
        }
        return result;
    }
};
