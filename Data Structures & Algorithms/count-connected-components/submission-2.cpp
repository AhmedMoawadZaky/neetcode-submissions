class Solution 
{
    unordered_map<int,vector<int>>graph;
    bool visited[105] = {false};
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        int ans = 0;
       for(auto & edge : edges)
       {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
       }
       for(int i = 0 ; i < n ; ++i)
       {
            if(!visited[i])
            {
                dfs(i);
                ++ans;
            }
       }
       return ans;
    }

    void dfs(int node)
    {
        if(visited[node])
        {
            return;
        }
        visited[node] = true;
        for(auto & n: graph[node])
        {
            dfs(n);
        }
    }

};
