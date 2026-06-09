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
    map<int,int>mpInorderIdx;
    int incremintalOfIdxRoot = 0;

public:
    TreeNode * DFS(vector<int> &preorder, int lRoot , int rRoot)
    {
        if(lRoot > rRoot)
        {
            return nullptr;
        }
        TreeNode * root = new TreeNode(preorder[incremintalOfIdxRoot++]);
        int idxOfRoot = mpInorderIdx[root->val];
        root->left = DFS(preorder,lRoot,idxOfRoot - 1);
        root->right = DFS(preorder,idxOfRoot + 1 , rRoot);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * rootAns = nullptr;
        for(int iter = 0 ; iter < inorder.size() ; ++iter)
        {
            mpInorderIdx[inorder[iter]] = iter;
        }
        rootAns = DFS(preorder, 0 , inorder.size() - 1);
        return rootAns;
    }
};
