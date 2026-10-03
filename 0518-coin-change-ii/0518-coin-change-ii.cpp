class Solution {
public:
    int solve(int amount, vector<int>& coins,int idx,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(idx>=coins.size()){
            return 0;
        }
        if(dp[amount][idx]!=-1){
            return dp[amount][idx];
        }
        int result =0;
        if(amount>=coins[idx]){
            result += solve(amount-coins[idx],coins,idx,dp);
        }
        result += solve(amount,coins,idx+1,dp);
        return dp[amount][idx] = result;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(5001,vector<int>(coins.size(),-1));
        int result = solve(amount,coins,0,dp);
        return result;
    }
};