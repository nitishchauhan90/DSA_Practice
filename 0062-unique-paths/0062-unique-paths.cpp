class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>& t){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int result =0;
        if(i+1<m){
            result = result+solve(m,n,i+1,j,t);
        }
        if(j+1<n){
            result = result+solve(m,n,i,j+1,t);
        }
        return t[i][j]=result;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, -1));
        int result = solve(m,n,0,0,t);
        return result;
    }
};