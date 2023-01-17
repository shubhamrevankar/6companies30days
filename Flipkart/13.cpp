// 695. Max Area of Island
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        grid[i][j]=0;
        int ret=1;

        if(i-1>=0 && grid[i-1][j]==1) ret += dfs(grid,i-1,j,m,n);

        if(j-1>=0 && grid[i][j-1]==1) ret += dfs(grid,i,j-1,m,n);

        if(i+1<m && grid[i+1][j]==1) ret += dfs(grid,i+1,j,m,n);

        if(j+1<n && grid[i][j+1]==1) ret += dfs(grid,i,j+1,m,n);

        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    res = max(res,dfs(grid,i,j,m,n));
            }
        }
        return res;
    }
};