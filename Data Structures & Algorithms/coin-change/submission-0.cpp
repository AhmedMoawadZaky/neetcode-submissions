class Solution {
public:
    unordered_map<int,int>dp;
    int coinChange(vector<int>& coins, int amount) 
    {
        int result = dfs(coins,amount);
        return  result != 1e9 ? result : -1;
    }
    int dfs(vector<int>&coins,int amount)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(dp[amount])
        {
            return dp[amount];
        }
        int result = 1e9;
        for(auto & coin : coins)
        {
            if(amount - coin >= 0)
            {
               result = min(result, 1 + dfs(coins,amount - coin));
            }
        }
        return dp[amount] = result;
    }
};
