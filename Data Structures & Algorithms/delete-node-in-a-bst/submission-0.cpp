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
    TreeNode* Min(TreeNode *root)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->left == nullptr)
        {
            return root;
        }
        return Min(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(key < root->val)
        {
            root->left = deleteNode(root->left , key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right , key);
        }
        else
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if(root->left == nullptr)
            {
                TreeNode * TempNode = root->right;
                free(root);
                return TempNode;
            }
            else if(root->right == nullptr)
            {
                TreeNode * TempNode = root->left;
                free(root);
                return TempNode;
            }
            else
            {
                TreeNode * MinNode = Min(root->right);
                root->val = MinNode->val;
                root->right = deleteNode(root->right , MinNode->val);
            }
        }
        return root;
    }   
};