class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashMap;
        vector<int>result;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(hashMap[target - nums[i]])
            {
                result.push_back(hashMap[target - nums[i]] - 1);
                result.push_back(i);
                break;
            }
            else
            {
                hashMap[nums[i]] = i + 1;
            }
        }
        return result;
    }
};
