class Solution {
    class UnionFind{
        vector<int>parent;
        vector<int>rank;
        public:
        UnionFind(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1,0);
            for(int i = 0 ; i <= n ; ++i)
            {
                parent[i] = i;
            }
        }
        bool union_(int node1,int node2)
        {
            node1 = find(node1);
            node2 = find(node2);
            if(node1 == node2)
            {
                return false;
            }
            if(rank[node1] > rank[node2])
            {
                parent[node2] = node1;
                rank[node1] += rank[node2];
            }
            else
            {
                parent[node1] = node2;
                rank[node2] += rank[node1];
            }
            return true;
        }
        int find(int node)
        {
            while(node != parent[node])
            {
                parent[node] = parent[parent[node]];
                node = parent[node];
            }
            return node;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind graph(edges.size());
        for(auto & edge : edges)
        {
            if(!graph.union_(edge[0],edge[1]))
            {
                return edge;
            }
        }
        return {};
    }
};
