class Solution {
    unordered_map<int,vector<int>>graph;
    vector<bool>visited;
    vector<bool>cycle;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        visited.resize(numCourses,false);
        cycle.resize(numCourses,false);
        for(int i = 0 ; i < numCourses ; ++i)
        {
            graph[i] = vector<int>();
        }
        for(const auto &edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 0 ; i < numCourses ; ++i)
        {
            if(!visited[i] && dfsCycle(i,visited,cycle))
            {
                return false;
            }
        }
        return true;
    }
    bool dfsCycle(int node,vector<bool>&visited,vector<bool>&cycle)
    {
        visited[node] = true;
        cycle[node] = true;
        for(auto & newNode : graph[node])
        {
            if(!visited[newNode] && dfsCycle(newNode,visited,cycle))
            {
                return true;
            }
            else if(cycle[newNode])
            {
                return true;
            }
        }
        cycle[node] = false;
        return false;
    }
};
