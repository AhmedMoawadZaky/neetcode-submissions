class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> cash(nums.size(),vector<int>(sum / 2 + 1,-1));
        bool result = false;
        if(sum % 2 == 0)
        {
            result = dfs(0, sum /2, nums,cash);
        }
        return result;
    }
    bool dfs(int idx, int target, vector<int>&nums, vector<vector<int>>&cash)
    {
        if(idx == nums.size())
        {
            return target == 0;
        }
        if(target < 0)
        {
            return false;
        }
        if(cash[idx][target] != -1)
        {
            return cash[idx][target];
        }
        cash[idx][target] = dfs(idx + 1, target, nums,cash) || dfs(idx + 1, target - nums[idx], nums,cash);
        return cash[idx][target];
    }
};
