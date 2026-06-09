class Solution {
    vector<vector<int>>graph;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        queue<int>Q;
        vector<int>result;
        vector<bool>visited(numCourses,false);
        vector<int>inDegree(numCourses,0);
        graph.resize(numCourses);
        for(auto & pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for(int i = 0 ; i < numCourses ; ++i)
        {
            if(inDegree[i] == 0)
            {
                Q.push(i);
            }
        }
        int counter = 0;
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            ++counter;
            for(auto &newNode : graph[node])
            {
                if(--inDegree[newNode] == 0)
                {
                    Q.push(newNode);
                }
            }
        }
        if(counter == numCourses)
        {
            for(int i = 0 ; i < numCourses ; i++)
            {
                postOrder(i,result,visited);
            }
            reverse(result.begin(),result.end());
        }
        return result;
    }
    void postOrder(int node , vector<int>&result, vector<bool>&visited)
    {
        if(visited[node])
        {
            return;
        }
        visited[node] = true;

        for(auto & nei : graph[node])
        {
            postOrder(nei,result,visited);
        }
        result.push_back(node);
    }
};
