class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int>memo(nums.size() + 1,-1);
        int sz = nums.size();
        int path1 = dfs(0,nums,memo,sz -1);
        memo = vector<int>(nums.size() + 1,-1); 
        int path2 = dfs(1,nums,memo,sz);
        return max({nums[0],path1,path2});
    }
    int dfs(int idx, vector<int>&nums, vector<int>&memo,int sz)
    {
        if(sz <= idx)
        {
            return 0;
        }
        if(memo[idx] != -1)
        {
            return memo[idx];
        }

        return memo[idx] = max(dfs(idx + 1, nums, memo,sz),(nums[idx] + dfs(idx + 2, nums, memo,sz)));
    }
};
