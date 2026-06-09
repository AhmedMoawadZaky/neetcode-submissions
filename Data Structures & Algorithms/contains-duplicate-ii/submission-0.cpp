class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int>HashSet;
        int left = 0 , right = 0;
        for(right = 0 ; right < nums.size() ; right++)
        {
            if(right - left > k)
            {
                HashSet.erase(nums[left]);
                ++left;
            }
            if(HashSet.find(nums[right]) != HashSet.end())
            {
                return true;
            }
            HashSet.insert(nums[right]);
        }    
        return false;
    }
};