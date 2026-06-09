class Solution {
public:
    string longestPalindrome(string s) 
    {
        int l = 0 , r = 0 , resIdx = 0 , maxLength = 0;
        for(int i = 0 ; i < s.size(); ++i)
        {
            l = r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if(r - l + 1 > maxLength)
                {
                    maxLength = r - l + 1;
                    resIdx = l;
                }
                ++r;
                --l;
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if(r - l + 1 > maxLength)
                {
                    maxLength = r - l + 1;
                    resIdx = l;
                }
                ++r;
                --l;
            }
        }

        return s.substr(resIdx,maxLength);
    }
};
