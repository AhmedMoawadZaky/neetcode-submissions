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
class Solution
{
	public:
	vector<int> rightSideView(TreeNode * root)
    {
        vector<int>rightSideViewResult = {};
        queue<TreeNode *> bfsQ;
        TreeNode * cur = nullptr;
        int length = 0;
        if(root != nullptr)
        {
            bfsQ.push(root);
        }

        while(!bfsQ.empty())
        {
            length = bfsQ.size();
            cur = bfsQ.front();
            rightSideViewResult.push_back(cur->val);
            for (int iter4BfsQ = 0 ; iter4BfsQ < length ; ++iter4BfsQ)
            {
                cur = bfsQ.front();
                bfsQ.pop();
                if(cur->right != nullptr)
                {
                    bfsQ.push(cur->right);
                }	

                if(cur->left != nullptr)
                {
                    bfsQ.push(cur->left);
                }
            }
        }
        return rightSideViewResult;
    }
};

