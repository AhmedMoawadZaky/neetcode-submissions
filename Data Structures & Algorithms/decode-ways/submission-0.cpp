class Solution {
public:
    int numDecodings(string s) 
    {
        unordered_map<int,int>mp;
        mp[s.size()] = 1;
        return dfs(0,s,mp);
    }
    int dfs(int idx,string str,unordered_map<int,int>&mp)
    {
        if(str[idx] == '0')
        {
            return 0;
        }
        if(mp[idx])
        {
            return mp[idx];
        }
        mp[idx] = dfs(idx + 1 , str,mp);
        if(idx < str.size() - 1 && (str[idx] == '1' ||(str[idx] == '2' && str[idx + 1] < '7')))
        {
            mp[idx] += dfs(idx + 2,str,mp);
        }
        return mp[idx];
    }
};
