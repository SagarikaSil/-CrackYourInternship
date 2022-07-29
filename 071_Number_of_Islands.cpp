// 200. Number of Islands

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j, int m, int n){
        grid[i][j]='0';
        
        if(j+1<n && grid[i][j+1]=='1')
            helper(grid,i,j+1,m,n);
        if(i+1<m && grid[i+1][j]=='1')
            helper(grid,i+1,j,m,n);
        if(j-1>=0 && grid[i][j-1]=='1')
            helper(grid,i,j-1,m,n);
        if(i-1>=0 && grid[i-1][j]=='1')
            helper(grid,i-1,j,m,n);
            
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), c=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    c++;
                    helper(grid,i,j,m,n);
                }
            }
        }
        return c;
    }
};