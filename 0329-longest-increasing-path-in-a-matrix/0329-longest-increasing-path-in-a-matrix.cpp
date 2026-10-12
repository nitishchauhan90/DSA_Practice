class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,int prev,vector<vector<int>>&dp){
        if(i>=matrix.size()||j>=matrix[0].size()||i<0||j<0||matrix[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result = 1;
        result=max(result,1+solve(matrix,i+1,j,matrix[i][j],dp));

        result=max(result,1+solve(matrix,i,j+1,matrix[i][j],dp));
  
        result=max(result,1+solve(matrix,i,j-1,matrix[i][j],dp));
        
        result=max(result,1+solve(matrix,i-1,j,matrix[i][j],dp));
        return dp[i][j] = result;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                result = max(result, solve(matrix, i, j, INT_MIN,dp));
            }
        }
        return result;
    }
};