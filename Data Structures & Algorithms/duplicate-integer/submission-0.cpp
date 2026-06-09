class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>countsMap;

        for(const auto &x : nums)
        {
            countsMap[x] += 1;
            if(countsMap[x] > 1)
            {
                return true;
            }
        }
        return false;
    }
};