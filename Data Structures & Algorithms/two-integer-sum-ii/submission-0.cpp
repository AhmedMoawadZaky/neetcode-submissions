class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int lIdx = 0 , rIdx = numbers.size() - 1;
        vector<int>result(2,0);
        while(lIdx < rIdx)
        {
            if(numbers[lIdx] + numbers[rIdx] < target)
            {
                ++lIdx;
            }
            else if(numbers[lIdx] + numbers[rIdx] > target)
            {
                --rIdx;
            }
            else
            {
                result = {lIdx + 1,rIdx + 1};
                break;
            }
        }

        return result;
    }
};
