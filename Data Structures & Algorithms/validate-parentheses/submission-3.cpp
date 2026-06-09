class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp = 
        {
            {'}','{'},
            {']','['},
            {')','('}
        };
        stack<char>st;
        for(const auto & c : s)
        {
            if(!st.empty() && st.top() == mp[c])
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};
