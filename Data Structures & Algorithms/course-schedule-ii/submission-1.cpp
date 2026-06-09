class Solution {
    vector<vector<int>>graph;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        queue<int>Q;
        vector<int>result(numCourses,0);
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
            result[counter] = node;
            ++counter;
            for(auto &newNode : graph[node])
            {
                if(--inDegree[newNode] == 0)
                {
                    Q.push(newNode);
                }
            }
        }
        if(counter != numCourses)
        {
            return {};
        }
        return result;
    }
   
};
