class Solution{

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int,vector<pair<int,int>>>graph;
        vector<int>shortestPath(105,1e7);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
        int node1,node2,cost,sz;
        for(int i = 1 ; i <= n ; ++i)
        {
            graph[i] = vector<pair<int,int>>();
        }
        for(auto &v : times)
        {
            node1 = v[0];
            node2 = v[1];
            cost = v[2];
            graph[node1].push_back({cost,node2});
        }
        PQ.push({0,k});
        shortestPath[k] = 0;
        while(!PQ.empty())
        {
            auto [cost,src] = PQ.top();
            PQ.pop();
            for(auto & [ncost,nsrc] : graph[src])
            {
                if(cost + ncost < shortestPath[nsrc])
                {
                    PQ.push({cost + ncost,nsrc});
                    shortestPath[nsrc] = cost + ncost;
                }
            }
        }
        auto maxElement = max_element(shortestPath.begin() + 1, shortestPath.begin() + n + 1);
        return *maxElement < 1e7 ? *maxElement : -1;
    }
};
