class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int uniqueResult = 0;
        int leftIter = 0,rightIter = 0;
        for(leftIter = 0,rightIter = 0;rightIter < nums.size();++rightIter)
        {
            if(val != nums[rightIter])
            {
                uniqueResult +=1;
                nums[leftIter] = nums[rightIter];
                leftIter += 1;
            }
        }
        return uniqueResult;
    }
};
