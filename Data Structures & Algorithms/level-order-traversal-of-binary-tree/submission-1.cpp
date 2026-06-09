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

class Solution{

public:
	
    vector<vector<int>> levelOrder(TreeNode * root)
    {
        vector<vector<int>>resultOfLevelOrder;
        queue<TreeNode *> bfsQ;
        TreeNode* cur = nullptr;
        int length = 0;
        int levelOrderCounter = 0;
        if(root != nullptr)
        {
            bfsQ.push(root);
        }
        while(!bfsQ.empty())
        {
            length = bfsQ.size();
            resultOfLevelOrder.emplace_back();
            for(int iterForBfsQ = 0 ; iterForBfsQ < length ; ++iterForBfsQ )
            {
                cur = bfsQ.front();
                bfsQ.pop();
                resultOfLevelOrder[levelOrderCounter].push_back(cur->val);
                if(cur->left != nullptr)
                {
                    bfsQ.push(cur->left);
                }
                if(cur->right != nullptr)
                {
                    bfsQ.push(cur->right);
                }

            }
            ++levelOrderCounter;
        }
        return resultOfLevelOrder;
    }

};

