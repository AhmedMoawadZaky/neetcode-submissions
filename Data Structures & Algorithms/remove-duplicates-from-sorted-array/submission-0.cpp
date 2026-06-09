class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueResult = 1;
        vector<int>outputList;
        int leftIter = 0,rightIter = 1;
        for(leftIter = 0,rightIter = 1;rightIter < nums.size();++rightIter)
        {
            if(nums[leftIter] != nums[rightIter])
            {
                uniqueResult +=1;
                outputList.push_back(nums[leftIter]);
                leftIter = rightIter;
            }
        }
        outputList.push_back(nums[rightIter - 1]);
        nums = outputList;
        return uniqueResult;
    }
};