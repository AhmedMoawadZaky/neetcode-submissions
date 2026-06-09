class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = nums[0];
        int curSum = 0;

        for(const auto &iter : nums)
        {
            curSum = max(curSum + iter,iter);
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};