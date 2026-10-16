class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&visit,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || visit[i][j]){
            return 0;
        }
        visit[i][j] = true;

        int result = 1;
        result += solve(grid,i+1,j,visit,n,m);
        result += solve(grid,i,j+1,visit,n,m);
        result += solve(grid,i-1,j,visit,n,m);
        result += solve(grid,i,j-1,visit,n,m);

        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j]){
                    result = max(result,solve(grid,i,j,visit,n,m));
                }
            }
        }
        return result;
    }
};