class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>>hashMap;
        vector<vector<string>>result;
        string sortedStr;
        for(int i = 0 ; i < strs.size() ; ++i)
        {
            sortedStr = strs[i];
            sort(&sortedStr[0] , &sortedStr[0] + sortedStr.length());
            hashMap[sortedStr].push_back(strs[i]);
        }
        for(const auto &str : hashMap)
        {
            result.push_back(str.second);
        }
        return result;
    }
};
