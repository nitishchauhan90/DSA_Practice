class Solution {
public:
    int solve(string& word1, string& word2,int i,int j,vector<vector<int>>&dp){
        if(j>=word2.size()){
            return word1.size()-i;
        }
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result=INT_MAX;
        if(word1[i]==word2[j]){
            result = solve(word1,word2,i+1,j+1,dp);
        }
        result = min(result,1+solve(word1,word2,i+1,j,dp));
        result = min(result,1+solve(word1,word2,i+1,j+1,dp));
        result = min(result,1+solve(word1,word2,i,j+1,dp));
        return dp[i][j]=result;
    }
    int minDistance(string word1, string word2) {
        if(word1.size()==0){
            return word2.size();
        }
        if(word2.size()==0){
            return word1.size();
        }
        vector<vector<int>>dp(501,vector<int>(501,-1));
        int result  = solve(word1,word2,0,0,dp);
        return result;
    }
};