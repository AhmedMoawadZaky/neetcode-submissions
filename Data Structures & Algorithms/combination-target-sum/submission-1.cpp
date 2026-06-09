class Solution {
    vector<vector<int>>result;
    vector<int>curSet;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        combinationSumHelper(nums,curSet,0,target);
        return result;
    }
    void combinationSumHelper(vector<int>&nums,vector<int>&curSet,int idx,int target)
    {
        if(idx == nums.size() || target < 0)
        {
            return;
        }
        if(target == 0)
        {
            result.push_back(curSet);
            return;
        }
        combinationSumHelper(nums,curSet,idx + 1 , target);

        curSet.push_back(nums[idx]);

        combinationSumHelper(nums,curSet,idx , target - nums[idx]);
        curSet.pop_back();
    }
};
