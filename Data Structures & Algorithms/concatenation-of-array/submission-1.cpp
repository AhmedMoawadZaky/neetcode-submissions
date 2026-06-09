class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        unsigned int actuleSize = nums.size();
        unsigned int newSize = 2U * actuleSize;
        vector<int>ans(newSize);
        for(unsigned int i = 0 ; i < newSize ; i++)
        {
            ans[i] = nums[i % actuleSize];
        }

        return ans;
    }
};