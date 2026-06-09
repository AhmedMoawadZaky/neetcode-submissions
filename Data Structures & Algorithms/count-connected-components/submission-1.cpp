class Solution 
{
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        set<int>result;
        for(int i = 0 ; i < n ; ++i)
        {
            parent[i] = i;
        }
        for(auto & edge : edges)
        {
            union_(edge[0],edge[1]);
        }
        for(int i = 0 ; i < n ; ++i)
        {
            result.insert(find(i));
        }
        return result.size();
    }
    bool union_(int node1, int node2)
    {
        node1 = find(node1);
        node2 = find(node2);

        if(node1 == node2)
        {
            return false;
        }
        else if(rank[node1] > rank[node2])
        {
            parent[node2] = parent[node1];
            rank[node1] += rank[node2];
        }
        else
        {
            parent[node1] = parent[node2];
            rank[node2] += rank[node1];
        }
        return true;
    }
    int find(int node)
    {
        while(node != parent[node])
        {
            // parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
};
