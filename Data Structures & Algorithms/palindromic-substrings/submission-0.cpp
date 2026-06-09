class Solution {
public:
    int countSubstrings(string s) 
    {
        int result = 0;
        int l = 0 , r = 0 , length = 0 , sz = s.size();
        for(int i = 0 ; i < sz; ++i)
        {
            l = r = i;

            while(l >= 0 && r < sz && s[l] == s[r])
            {
                l--;
                r++;                
                result++;
            }
            l = i;
            r = i + 1;

            while(l >= 0 && r < sz && s[l] == s[r])
            {
                l--;
                r++; 
                result++;
            }
        }
        return result;
    }
};
