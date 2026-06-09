class Solution {
    unordered_map<int,vector<int>>graph;
 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {

        for(int i = 0 ; i < numCourses ; ++i)
        {
            graph[i] = vector<int>();
        }
        for(const auto &edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
        }
        return !isCyclicKahn(numCourses,graph);
    }
    bool isCyclicKahn(int V, unordered_map<int,vector<int>>& adj) 
    {
        vector<int> in_degree(V, 0);
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                in_degree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) 
        {
            int u = q.front(); q.pop();
            count++;
            for (int v : adj[u])
            {
                if (--in_degree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return count != V; 
    }
};
