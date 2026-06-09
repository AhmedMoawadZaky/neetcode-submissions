class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int>memo(nums.size() + 1,-1);
        return dfs(0,nums,memo);
    }
    int dfs(int idx, vector<int>&nums, vector<int>&memo)
    {
        if(nums.size() <= idx)
        {
            return 0;
        }
        if(memo[idx] != -1)
        {
            return memo[idx];
        }

        return memo[idx] = max(dfs(idx + 1, nums, memo),(nums[idx] + dfs(idx + 2, nums, memo)));
    }
};
