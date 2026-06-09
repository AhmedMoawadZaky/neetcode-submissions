class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int length = 1;
        int result = 0;
        int counter = 0;
        unordered_set<int>hashSet(nums.begin(),nums.end());
        for(const auto & number : hashSet)
        {
            if(hashSet.find(number - 1) == hashSet.end())
            {
                while(hashSet.find(number + length) != hashSet.end())
                {
                    length++;
                    ++counter;
                }
                result = max(result,length);
                length = 1;
            }
        }
        return result;
    }
};
