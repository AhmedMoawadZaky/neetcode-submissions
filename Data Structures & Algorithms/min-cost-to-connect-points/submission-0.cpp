class UnionFind{
    public:
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
    UnionFind(int n)
    {
        for(int i = 0 ; i < n ; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
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
    bool unionN(int node1 , int node2)
    {
        node1 = find(node1);
        node2 = find(node2);

        if(node1 == node2)
        {
            return false;
        }
        if(rank[node1] > rank[node2])
        {
            rank[node1] += rank[node2];
            parent[node2] = node1;
        }
        else
        {
            rank[node2] += rank[node1];
            parent[node1] = node2;
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int sz = points.size();
        int cost = 0;
        int result = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minHeap;
        UnionFind unionObj(sz);
       
        for(int u = 0 ; u < sz ; ++u)
        {
            for(int v = u + 1 ; v < sz ; ++v)
            {
                cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                minHeap.push({cost,u,v});
            }
        }
        while(sz > 1)
        {
            auto [cost,u,v] = minHeap.top();
            minHeap.pop();
            if(unionObj.unionN(u,v))
            {
                result += cost;
                sz -= 1;
            }
        }
        return result;
    }
};
