class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueResult = 1;
        int leftIter = 0,rightIter = 1;
        for(leftIter = 0,rightIter = 1;rightIter < nums.size();++rightIter)
        {
            if(nums[leftIter] != nums[rightIter])
            {
                uniqueResult +=1;
                nums[leftIter + 1] = nums[rightIter];
                leftIter += 1;
            }
        }
        return uniqueResult;
    }
};