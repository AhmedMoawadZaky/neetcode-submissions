class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0,currentSize = 0,tempNum = 0;
        vector<int>scoreHolder;
        for(const auto & op : operations)
        {
            currentSize = scoreHolder.size();
            if(op == "+")
            {
                scoreHolder.push_back(scoreHolder[currentSize - 1] + scoreHolder[currentSize - 2]);
                sum += scoreHolder[currentSize];
            }
            else if(op == "D")
            {
                scoreHolder.push_back(scoreHolder[currentSize - 1] * 2u);
                sum += scoreHolder[currentSize];
            }
            else if(op == "C")
            {
                sum -= scoreHolder[currentSize - 1];
                scoreHolder.pop_back();
            }
            else
            {
                tempNum = stoi(op);
                scoreHolder.push_back(tempNum);
                sum += scoreHolder[currentSize];
            }
        }
        return sum;
    }
};