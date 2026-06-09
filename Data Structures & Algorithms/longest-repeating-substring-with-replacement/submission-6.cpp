class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int>counts;
        int ans = 0 , l = 0,maxF = 0;
        for(int r = 0 ; r < s.size() ; ++r)
        {
            counts[s[r]]++;
            maxF = max(maxF , counts[s[r]]);
            if((r - l + 1) - maxF > k)
            {
                counts[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
