class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int nmul2 = n * 2U;
        nums.resize(nmul2);
        for(int iter = n ; iter < nmul2 ; ++iter)
        {
            nums[iter] = nums[iter - n];
        }
        return nums;
    }
};