
class TrieNode
{
    public:
    unordered_map<char,TrieNode*>children;
    bool isEndOfWord;
    TrieNode():isEndOfWord(false){}
};
class Solution 
{
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    TrieNode* root = new TrieNode();
    TrieNode* root1 = new TrieNode();
    int rows = 0 , cols = 0;
    vector<string>ans;
    vector<vector<bool>> visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        rows = board.size();
        cols = board[0].size();
        for(const auto str : words)
        {
            insert1(str);
        }
        for(int i = 0 ; i< rows ; i++)
        {
            for(int j = 0 ; j < cols ; ++j)
            {
                visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
                dfs(i,j,"",board);
            }
        }
        for(const auto str : words)
        {
            if(search(str))
            {
                ans.push_back(str);
            }
        }
        return ans;
    }

    void dfs(int row, int col, string currentWord,vector<vector<char>>& board) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col]) 
        {
            return;
        }
        visited[row][col] = true;
        currentWord += board[row][col];
        insert(currentWord);
        if (startsWith(currentWord)) 
        {
            for (auto& dir : directions) 
            {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                dfs(newRow, newCol, currentWord,board);
            }
        }
        visited[row][col] = false;
    }
    void insert(const string& word)
    {
        TrieNode* current = root;
        for(const char& c : word)
        {
            if(!current->children[c])
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }
    void insert1(const string& word)
    {
        TrieNode* current = root1;
        for(const char& c : word)
        {
            if(!current->children[c])
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }
    bool search(const string& word)
    {
        TrieNode* current = root;
        for(const char & c : word)
        {
            if(!current->children[c])
            {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }
     bool startsWith(const string& prefix) 
     {
        TrieNode* current = root1;
        for (char c : prefix) {
            if (!current->children[c]) 
            {
                return false;
            }
            current = current->children[c];
        }
        return true;
    }
};
