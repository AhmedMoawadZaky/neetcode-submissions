class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0,currentSize = 0,tempNum = 0;
        int iterScoreHolder = 0;
        int *nums = new int [1005];
        for(const auto & op : operations)
        {
            if(op == "+")
            {
                nums[iterScoreHolder] = nums[iterScoreHolder - 1] + nums[iterScoreHolder - 2];
                sum += nums[iterScoreHolder];
                ++iterScoreHolder;
            }
            else if(op == "D")
            {
                nums[iterScoreHolder] = 2 * nums[iterScoreHolder - 1];
                sum += nums[iterScoreHolder];
                ++iterScoreHolder;
            }
            else if(op == "C")
            {
                iterScoreHolder -= 1;
                sum -= nums[iterScoreHolder];
            }
            else
            {
                tempNum = stoi(op);
                nums[iterScoreHolder] = tempNum;
                sum += nums[iterScoreHolder];
                ++iterScoreHolder;
            }
        }
        return sum;
    }
};