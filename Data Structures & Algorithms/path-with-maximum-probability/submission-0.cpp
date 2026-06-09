class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        unordered_map<int,vector<pair<int,double>>>graph;
        priority_queue<pair<double,int>>PQ;
        vector<double>bestPath(n,0.0);
        int src,dis;
        double prob;
        for(int i = 0 ; i < n ; i++)
        {
            graph[i] = vector<pair<int,double>>();
        }
        for(int i = 0 ; i < edges.size() ; i++)
        {
            src = edges[i][0];
            dis = edges[i][1];
            prob = succProb[i];
            graph[src].push_back({dis,prob});
            graph[dis].push_back({src,prob});
        }
        PQ.push({1.0,start_node});
        bestPath[start_node] = 1.0;
        while(!PQ.empty())
        {
            auto [prob,src] = PQ.top();
            PQ.pop();
            for(auto &[nsrc,nprob] : graph[src])
            {
                if(prob * nprob > bestPath[nsrc])
                {
                    PQ.push({prob * nprob,nsrc});
                    bestPath[nsrc] = prob * nprob;
                }
            }
        }
       
        return bestPath[end_node];
    }
};