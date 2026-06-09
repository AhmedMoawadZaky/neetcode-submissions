class Solution {
    vector<vector<int>>result;
    vector<int>curSet;
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        subSetsHelper(nums,0,curSet);
        return result;
    }
    void subSetsHelper(vector<int>& nums,int idx,vector<int>&curSet)
    {
        if(idx == nums.size())
        {
            result.push_back(curSet);
            return;
        }
        subSetsHelper(nums,idx + 1,curSet);

        curSet.push_back(nums[idx]);
        subSetsHelper(nums,idx + 1,curSet);

        curSet.pop_back();

    }
};
