class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) 
    {
        int sumOfSet = 0,ans = 0;
        int left = 0;
        for(int right = 0 ; right < nums.size(); ++right)
        {
            sumOfSet += nums[right];
            if((right - left + 1) == k)
            {
                if(sumOfSet / k >= threshold)
                {
                    ++ans;
                }
                sumOfSet -= nums[left];
                left++;
            }
        }
        return ans;
    }
};