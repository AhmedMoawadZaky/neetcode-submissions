class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxPro = nums[0];
        int curMin = 1, curMax = 1;

        for (int n : nums) 
        {
            int tmp = curMax * n;
            curMax = max({n, curMax * n , curMin * n});
            curMin = min({n, tmp , curMin * n});
            maxPro = max(maxPro,curMax);
        }
        return maxPro;
    }
};
