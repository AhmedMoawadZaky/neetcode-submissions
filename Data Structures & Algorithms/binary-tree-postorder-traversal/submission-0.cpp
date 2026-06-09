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
    private:
        vector<int>result;
        void postorderTraversalHelper(TreeNode* root)
        {
            if(root == nullptr)
            {
                return;
            }
            postorderTraversalHelper(root->left);
            postorderTraversalHelper(root->right);
            result.push_back(root->val);
        }
    public:
        vector<int> postorderTraversal(TreeNode* root) 
        {
            postorderTraversalHelper(root);
            return result;
        }
};