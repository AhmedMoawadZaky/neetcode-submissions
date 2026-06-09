class Solution {
public:
    int trap(vector<int>& height) 
    {
        int maxWater = 0;
        int length = height.size();
        vector<int>leftMax(length);
        vector<int>rightMax(length);
        leftMax[0] = height[0];
        rightMax[length - 1] = height[length - 1];
        for(int j = 1 ; j < length ; ++j)
        {
            leftMax[j] = max(leftMax[j - 1],height[j]);
        }
        for(int j = length  - 2 ; j >= 0 ; --j)
        {
            rightMax[j] = max(rightMax[j + 1],height[j]);
        }
        for(int i = 0 ; i < length ; ++i)
        {  
            maxWater += min(leftMax[i],rightMax[i]) - height[i];
        }
        return maxWater;
    }
};
