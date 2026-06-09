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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>Ans;
        queue<TreeNode *> Q;
        int lenth = 0;

        if(root != nullptr)
        {
            Q.push(root);
        }
        while(!Q.empty())
        {
            lenth = Q.size();
            Ans.push_back(Q.front()->val);
            for(int iterQ = 0 ; iterQ < lenth ; ++iterQ)
            {
                TreeNode * cur = Q.front();
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
        return Ans;
    }
   
};
