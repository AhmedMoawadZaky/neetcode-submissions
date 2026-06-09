class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>hashMap;
        vector<int>result;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(hashMap[target - nums[i]])
            {
                result = {hashMap[target - nums[i]] - 1,i};
            }
            hashMap[nums[i]] = i + 1;
        }
        return result;
    }
};
