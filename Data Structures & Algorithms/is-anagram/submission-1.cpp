class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int freqArray[26] = {};
        bool ans = true;
        for(int i = 0 ; i < s.length() ; ++i)
        {
            freqArray[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t.length() ; ++i)
        {
            freqArray[t[i] - 'a']--;
        }
        for(int i = 0 ; i < 26 ; ++i)
        {
            if(freqArray[i])
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};
