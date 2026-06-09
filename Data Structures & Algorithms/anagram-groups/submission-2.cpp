class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int strSize = strs.size();
        unordered_map<string,vector<string>>dataSet;
        vector<vector<string>>ans;
        string tempStr = "";
        for(int i = 0 ; i < strSize ; ++i)
        {
            tempStr = strs[i];
            sort(tempStr.begin(),tempStr.end());
            cout<<tempStr<<endl;
            if(!dataSet.count(tempStr))
            {
                dataSet[tempStr] = vector<string>();
            }
            dataSet[tempStr].push_back(strs[i]);
        }
        for(const auto &vec : dataSet)
        {
            ans.push_back(vec.second);
        }
        return ans;
    }
};
