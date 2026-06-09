class TreeNode {
    public:
    int m_key;
    int m_val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int k , int val):m_key(k),m_val(val)
    {
        left = nullptr;
        right = nullptr;
    }
};
class TreeMap {
    TreeNode * root = nullptr;
    public:
    void inorderTraversal(TreeNode *root, vector<int> &result) 
    {
        if (root != nullptr) 
        {
            inorderTraversal(root->left, result);
            result.push_back(root->m_key);
            inorderTraversal(root->right, result);
        }
    }
    TreeNode* findMin(TreeNode *node) 
    {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    TreeNode * removeTraversal(TreeNode * cur , int key)
    {
        if(cur == nullptr)
        {
            return nullptr;
        }
        {
            if(cur->m_key < key)
            {
                cur = removeTraversal(cur->right,key);
            }
            else if(cur->m_key > key)
            {
                cur = removeTraversal(cur->left,key);
            }
            else
            {
                if(cur-> left == nullptr)
                {
                    TreeNode * tempNode = cur->right;
                    free(cur);
                    return tempNode;
                }
                else if(cur-> right == nullptr)
                {
                    TreeNode * tempNode = cur->left;
                    free(cur);
                    return tempNode;
                }
                else
                {
                    TreeNode *minNode = findMin(cur->right);
                    cur->m_val = minNode->m_val;
                    cur->m_key = minNode->m_key; 
                    cur->right = removeTraversal(cur->right,minNode->m_key);
                }
            }
        }
        return cur;
    }
    void insert(int key, int val) 
    {
        if(root == nullptr)
        {
            root = new TreeNode(key,val);
        }
        else
        {
            TreeNode * cur = root;
            while(cur != nullptr)
            {
                if( key < cur->m_key)
                {
                    if(cur->left == nullptr)
                    {
                        cur->left = new TreeNode(key , val);
                        break;
                    }
                    cur = cur->left;
                }
                else if (key > cur->m_key)
                {
                    if(cur->right == nullptr)
                    {
                        cur->right = new TreeNode(key , val);
                        break;
                    }
                    cur = cur->right;
                }
                else
                {
                    cur->m_val = val;
                    break;
                }
            }
        }
    }

    int get(int key) 
    {
        TreeNode * cur = root;
        bool getStatusOkay = false;
        int resultOfGetMap = 0;

        while(cur != nullptr)
        {
            if(key < cur->m_key)
            {
                cur = cur->left;
            }
            else if(key > cur->m_key)
            {
                cur = cur->right;
            }
            else
            {
                getStatusOkay = true;
                resultOfGetMap = cur->m_val;
                break;
            }
        }

        return (getStatusOkay ? resultOfGetMap : -1);
    }

    int getMin() 
    {
        TreeNode * cur = root;
        bool getMinStatus = true;;
        if(root == nullptr)
        {
            getMinStatus = false;
        }
        while(cur != nullptr && cur->left != nullptr)
        {
            cur = cur->left;
        }
        return (getMinStatus ? cur->m_val : -1);
    }

    int getMax() 
    {
        TreeNode * cur = root;
        bool getMaxStatus = true;;
        if(cur == nullptr)
        {
            getMaxStatus = false;
        }
        while(cur != nullptr && cur->right != nullptr)
        {
            cur = cur->right;
        }
        return (getMaxStatus ? cur->m_val : -1);

    }

    void remove(int key) 
    {
        root = removeTraversal(root , key);
    }

    std::vector<int> getInorderKeys() 
    {
        vector<int>result;
        inorderTraversal(root,result);
        return result;
    }
};
