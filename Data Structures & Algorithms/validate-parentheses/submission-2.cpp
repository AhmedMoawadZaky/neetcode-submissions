class Solution {
public:
    bool isValid(string s) {
        stack<char> SC;
        map<char,char>mp = {
            {'(',')'},
            {'[',']'},
            {'{','}'}        
        };
        for(const auto iter : s)
        {
            if(mp[iter])
            {
                SC.push(iter);
            }
            else if(!SC.empty() && mp[SC.top()] == iter)
            {
                SC.pop();
            }
            else
            {
                return false;
            }
        }
        return SC.empty();
    }
};
