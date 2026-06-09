class Solution {
    vector<vector<int>>result;
    vector<int>subset;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        subSetHelper(0,result,subset,nums);

        return result;
    }
    void subSetHelper(int iterI ,  vector<vector<int>>&result, vector<int>& subset , vector<int>& nums)
    {
        if(iterI >=  nums.size())
        {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[iterI]);
        subSetHelper(iterI + 1,result,subset,nums);
        subset.pop_back();
        subSetHelper(iterI + 1,result,subset,nums);
    }
};
