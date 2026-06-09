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
        queue<TreeNode *>Q;
        vector<vector<int>>result;
        int levelOfBST = 0;
        if(root != nullptr)
        {
            Q.push(root);
        }
        while(!Q.empty())
        {
            int length = Q.size();
            result.push_back(vector<int>());
            for(int i = 0 ; i < length ; ++i)
            {
                TreeNode* cur = Q.front();
                Q.pop();
                if(cur->left)
                {
                    Q.push(cur->left);
                }
                if(cur->right)
                {
                    Q.push(cur->right);
                }
                result[levelOfBST].push_back(cur->val);
            }
            ++levelOfBST;
        }
    return result;
    }
};
