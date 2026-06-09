class Solution {
    vector<string>result;
    unordered_map<char,string>mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"qprs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    void letterHelper(int idx ,string cur , string digits)
    {
        if(cur.size() == digits.size())
        {
            result.push_back(cur);
            return;
        }
        
        for(auto & ch : mp[digits[idx]])
        {
            letterHelper(idx + 1, cur + ch,digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
        {
            return result;
        }
        letterHelper(0,"",digits);
        return result;
    }
};
