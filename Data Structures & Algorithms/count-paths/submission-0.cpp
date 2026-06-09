class Solution {
    vector<vector<int>>memo;
public:
    int uniquePaths(int m, int n) 
    {
        memo.resize(m,vector<int>(n,-1));

        return uniquePathsHelper(0 , 0 ,m ,n);
    }
    int uniquePathsHelper(int i , int j , int m , int n)
    {
        if(i >= m || j >= n)
        {
            return 0;
        }
        if(i == m -1 && j == n - 1)
        {
            return 1;
        }
        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }
        return memo[i][j] = uniquePathsHelper(i + 1, j, m, n) + uniquePathsHelper(i , j + 1, m, n);
    }
};
