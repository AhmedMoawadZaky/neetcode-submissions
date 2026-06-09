class Solution {
public:
    int trap(vector<int>& height) 
    {
        int maxWater = 0;
        int length = height.size();


        for(int i = 0 ; i < length ; ++i)
        {
            int leftMax = height[i];
            int rightMax = height[i];
            for(int j = 0 ; j < i ; ++j)
            {
                leftMax = max(leftMax,height[j]);
            }
            for(int j = i ; j < length ; ++j)
            {
                rightMax = max(rightMax,height[j]);
            }
            maxWater += min(leftMax,rightMax) - height[i];
        }
        return maxWater;
    }
};
