class Solution {
public:
    bool isPalindrome(string s) 
    {
        int l = 0 , r = s.size() - 1;
        bool status = true;
        while(l < r)
        {
            if(!isalnum(s[l]))
            {
                ++l;
                continue;
            }
            if(!isalnum(s[r]))
            {
                --r;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r]))
            {
                cout<<s[l] << " " << s[r] <<endl;
                status = false;
                break;
            }
            ++l;
            --r;
        }
        return status;
    }
};
