class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int sChars[26] = {0};
        int tChars[26] = {0};

        for(const auto &iter : s)
        {
            sChars[iter - 'a'] += 1;
        }
        for(const auto &iter : t)
        {
            tChars[iter - 'a'] += 1;
        }
        for(int iter = 0 ; iter < 26 ; ++iter)
        {
            if(sChars[iter] != tChars[iter])
            {
                return false;
            }
        }
        return true;
    }
};
