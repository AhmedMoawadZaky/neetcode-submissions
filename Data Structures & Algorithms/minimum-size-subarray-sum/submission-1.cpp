class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        vector<int>lookUpList(nums.size() + 1,0);
        int ans = 100005;
        int left = 0 , right = 1;
        for(int i = 1 ;i < lookUpList.size() ; ++i)
        {
            lookUpList[i] += (nums[i - 1] + lookUpList[i - 1]);
        }
        while(left < right && right < nums.size() + 1)
        {
            if(lookUpList[right] - lookUpList[left] < target)
            {
                right++;
            }
            else
            {
                ans = min(ans,right - left);
                left++;
            }
        }
        return (ans < 10005) ? ans : 0;
    }
};