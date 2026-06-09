class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>hashMap;
        vector<int>result;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            hashMap[nums[i]] += 1;
        }
        for(const auto pairMap : hashMap)
        {
            pq.push({pairMap.second,pairMap.first});
        }
        while(k--)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
