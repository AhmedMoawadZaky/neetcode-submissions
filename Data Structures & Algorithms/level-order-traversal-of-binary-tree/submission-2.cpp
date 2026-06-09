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
        vector<vector<int>>result = {};
        vector<int>setOfNodes = {};
        queue<TreeNode *>Q = {};
        int levelIdx = 0;
        int length = 0;
        if(root != nullptr)
        {
            Q.push(root);
        }
        while(!Q.empty())
        {
            length = Q.size();
            for(int i = 0 ; i < length ; ++ i)
            {
                TreeNode * Temp = Q.front();
                Q.pop();
                if(Temp->left != nullptr)
                {
                    Q.push(Temp->left);
                }
                if(Temp->right != nullptr)
                {
                    Q.push(Temp->right);
                }
                setOfNodes.push_back(Temp->val);
            }

            result.push_back(setOfNodes);
            setOfNodes.clear();
        }
        return result;
    }
};
