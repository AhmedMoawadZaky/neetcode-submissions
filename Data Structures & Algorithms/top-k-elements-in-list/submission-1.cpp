class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>>frequancy(nums.size() + 1);
        unordered_map<int,int>hashMap;
        vector<int>result;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            hashMap[nums[i]] += 1;
        }
        for(const auto pairMap : hashMap)
        {
            frequancy[pairMap.second].push_back(pairMap.first);
        }
        for(int i = nums.size() ; i >= 0 ; i--)
        {
            for(const int & freq : frequancy[i])
            {
                result.push_back(freq);
                if(result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};
