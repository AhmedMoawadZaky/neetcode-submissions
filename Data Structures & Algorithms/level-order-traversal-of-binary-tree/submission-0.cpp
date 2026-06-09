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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderResult;
        queue<TreeNode *> quOfTree;
        int length = 0;
        int levels = 0;
        if(root != nullptr)
        {
            quOfTree.push(root);
        }
        while(!quOfTree.empty())
        {
            length = quOfTree.size();
            levelOrderResult.push_back(vector<int>());
            for(int iterOfQ = 0 ; iterOfQ < length ; ++ iterOfQ)
            {
                TreeNode * curNode = quOfTree.front();
                quOfTree.pop();
                levelOrderResult[levels].push_back(curNode->val);
                if(curNode-> left != nullptr)
                {
                    quOfTree.push(curNode-> left);
                }
                if(curNode->right != nullptr)
                {
                    quOfTree.push(curNode->right);
                }
            }
            levels += 1;
        }
        return levelOrderResult;
    }
};
