class Solution {
private:
    vector<vector<int>>result;
    vector<int>curSet;
    void combinationHelper(int number , int size , int k)
    {
        if(curSet.size() == k)
        {
            result.push_back(curSet);
            return;
        }
        if(number > size)
        {
            return;
        }
        curSet.push_back(number);
        combinationHelper(number + 1, size, k);
        curSet.pop_back();

        combinationHelper(number + 1, size, k);
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        combinationHelper(1 , n , k);

        return result;
    }
};