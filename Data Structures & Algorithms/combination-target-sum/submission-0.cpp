class Solution {
    vector<vector<int>>resultOfCombination;
    vector<int>setOfElement;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        combinHelper(nums,target,setOfElement,0);

        return resultOfCombination;
    }

    void combinHelper(vector<int>&nums,int target,vector<int>setOfElement,int iterIdx)
    {
        if(iterIdx >= nums.size() || target < 0)
        {
            return;
        }
        if(target == 0)
        {
            resultOfCombination.push_back(setOfElement);
            return;
        }
        setOfElement.push_back(nums[iterIdx]);

        combinHelper(nums, target - nums[iterIdx], setOfElement, iterIdx);
        setOfElement.pop_back();
        combinHelper(nums, target, setOfElement, iterIdx + 1);

    }
};
