class Solution {
    vector<vector<int>>memo;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();
        int m = grid.size();
        
        memo.resize(m,vector<int>(n,-1));

        return uniquePathsHelper(0 , 0 ,m ,n,grid);
    }
    int uniquePathsHelper(int i , int j , int m , int n,vector<vector<int>>& grid)
    {
        if(i >= m || j >= n || grid[i][j] == 1)
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
        return memo[i][j] = uniquePathsHelper(i + 1, j, m, n,grid) + uniquePathsHelper(i , j + 1, m, n,grid);
    }
};
