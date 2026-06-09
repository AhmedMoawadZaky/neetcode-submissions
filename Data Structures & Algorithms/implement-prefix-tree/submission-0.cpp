class PrefixTree {
    class TrieNode
    {
        public:
        unordered_map<char,TrieNode *>child;
        bool isTheEndOfWord;
        TrieNode()
        {
            isTheEndOfWord = false;
        }
    };
public:
    TrieNode *root;
    PrefixTree():root(new TrieNode()) 
    {
        
    }
    
    void insert(string word) 
    {
        TrieNode * cur = root;
        for(const char & c : word)
        {
            if(cur->child[c] == nullptr)
            {
                cur->child[c] = new TrieNode();
            }
            cur = cur->child[c];
        }
        cur->isTheEndOfWord = true;
    }
    
    bool search(string word) 
    {
        TrieNode * cur = root;
        for(const char & c : word)
        {
            if(cur->child[c] == nullptr)
            {
                return false;
            }
            cur = cur->child[c];
        }
        return  cur->isTheEndOfWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode * cur = root;
        for(const char & c : prefix)
        {
            if(cur->child[c] == nullptr)
            {
                return false;
            }
            cur = cur->child[c];
        }
        return  true;
    }
};
