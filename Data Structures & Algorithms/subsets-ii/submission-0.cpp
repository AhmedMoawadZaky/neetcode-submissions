class Solution {

private:
    void subsetsHelper(int idx,vector<int>& nums,vector<int>&curSet,vector<vector<int>>&result)
    {
        if(idx == nums.size())
        {
            result.push_back(curSet);
            return;
        }

        curSet.push_back(nums[idx]);

        subsetsHelper(idx + 1,nums,curSet,result);

        curSet.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx + 1])
        {
            idx += 1;
        }
        subsetsHelper(idx + 1,nums,curSet,result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>curSet;
        subsetsHelper(0,nums,curSet,result);

        return result;
    }
};
