class Solution {
public:
    int numDecodings(string s) 
    {
        unordered_map<int,int>mp;
        int sz = s.size();
        mp[sz] = 1;
        for(int i  = sz - 1 ; i >= 0 ; i--)
        {
            if(s[i] == '0')
            {
                mp[i] = 0;
            }
            else
            {
                mp[i] = mp[ i + 1];
                if(i + 1 < sz && (s[i] =='1' ||(s[i] == '2' && s[i + 1] <'7')))
                {
                    mp[i] += mp[i + 2];
                }
            }
           
        }
        return mp[0];
    }
};
