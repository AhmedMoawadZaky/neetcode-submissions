class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>s(nums.begin(),nums.end());
        int result = 0;
        int counter = 1;
        for(auto & num : nums)
        {
            if(s.find(num - 1) == s.end())
            {
                while(s.find(num + counter) != s.end())
                {
                    ++counter;
                }
                result = max(result,counter);
                counter = 1;
            }
        }
        return result;
    }
};
