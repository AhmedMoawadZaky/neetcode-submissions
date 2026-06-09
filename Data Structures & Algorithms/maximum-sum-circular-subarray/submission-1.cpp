class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int gMax = nums[0] , gMin = nums[0];
        int curMin = 0 , curMax = 0;
        int sumOfNums = 0;

        for(const auto &number : nums)
        {
            curMin = min(curMin + number , number);
            curMax = max(curMax + number , number);

            sumOfNums += number;

            gMax = max(gMax,curMax);
            gMin = min(gMin,curMin);
        }
        return (sumOfNums > 0) ? max(sumOfNums - gMin,gMax): gMax;
    }
};
