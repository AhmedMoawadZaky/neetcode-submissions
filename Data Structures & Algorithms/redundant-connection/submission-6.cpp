#include <cstring>

class Solution {
    vector<int>parent;
    vector<int>rank;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int SZ = edges.size() + 1;
        parent.resize(SZ);
        rank.resize(SZ,1);
        for(int i = 1 ; i < SZ ; ++i)
        {
           parent[i] = i;
        }
        for(const auto &edge : edges)
        {
            if(!union_(edge[0],edge[1]))
            {
                return edge;
            }
        }
        return edges[0];
    }

    int find(int node)
    {
        while(node != parent[node])
        {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return parent[node];
    }
    bool union_(int node1, int node2)
    {
        node1 = find(node1);
        node2 = find(node2);
        if(node1 == node2)
        {
            return false;
        }
        if(rank[node1] < rank[node2])
        {
            parent[node1] = node2;
            rank[node2] += rank[node1];
        }
        else
        {
            parent[node2] = node1;
            rank[node1] += rank[node2];
        }
        return true;
    }
};
