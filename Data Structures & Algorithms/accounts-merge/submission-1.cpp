class Solution {
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string,int>accsIds;
        unordered_map<int,vector<string>>emailsRoot;
        vector<vector<string>>result;

        for(int idxAcc = 0 ; idxAcc < accounts.size() ; ++idxAcc)
        {
            parent[idxAcc + 1] = idxAcc + 1;
            int jdx = 0;
            for(const auto &jdxAcc : accounts[idxAcc])
            {
                if(jdx == 0)
                {
                    jdx = 1;
                    continue;
                }
                if(accsIds[jdxAcc])
                {
                    union_(idxAcc + 1,accsIds[jdxAcc]);
                }
                else
                {
                    accsIds[jdxAcc] = idxAcc + 1;
                }
            }
        }
        for(auto & [email,idx] : accsIds)
        {
            emailsRoot[find(idx)].push_back(email);
        }
        int idxC = 0;
        for(auto &[idx , email] : emailsRoot)
        {
            sort(email.begin(),email.end());
            result.push_back(vector<string>());
            cout<< accounts[idx - 1][0] <<endl;
            result[idxC].push_back(accounts[idx - 1][0]);
            result[idxC].insert(result[idxC].end(),email.begin(),email.end());
            idxC++;
        }
        return result;
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