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

    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * curIter = root;
        stack<TreeNode *> TreeSTK;
        vector<int>vecAns = {};

        while(curIter != nullptr || !TreeSTK.empty())
        {
            while(curIter != nullptr )
            {
                TreeSTK.push(curIter);
                curIter = curIter->left;
            }
            curIter = TreeSTK.top();
            TreeSTK.pop();
            vecAns.push_back(curIter->val);
            curIter = curIter->right;
        }

        return vecAns;
    }
};