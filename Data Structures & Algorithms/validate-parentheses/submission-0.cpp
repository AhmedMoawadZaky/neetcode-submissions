class Solution {
public:
    bool isValid(string s) {
        stack<char> SC;
        char temp = ' ';
        for(const auto iter : s)
        {
            if(!SC.empty())
            {
                temp = SC.top();
            }
            else
            {
                temp = iter;
            }
            if((temp == '(' && iter == ')') || (temp == '[' && iter == ']') ||(temp == '{' && iter == '}'))
            {
                SC.pop();
            }
            else
            {
                SC.push(iter);
            }
        }
        return SC.empty();
    }
};
