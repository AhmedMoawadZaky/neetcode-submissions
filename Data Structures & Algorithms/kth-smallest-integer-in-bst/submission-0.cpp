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
    int ans = 0,cunt = 0;
    int kthSmallest(TreeNode* root, int k) {
        cunt = k;
        inorderTraversing(root);
        return ans;
    }
    void inorderTraversing(TreeNode * root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorderTraversing(root->left);
        --cunt;
        if(cunt == 0)
        {
            ans = root->val;
        }
        inorderTraversing(root->right);
    }
};
