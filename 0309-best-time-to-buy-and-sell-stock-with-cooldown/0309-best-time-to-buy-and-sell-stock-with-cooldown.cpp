class Solution {
public:
    int solve(vector<int>& prices,int idx,bool buy,bool sell,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        int profit = 0;
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            int buy1 = solve(prices,idx+1,0,1,dp)-prices[idx];
            int buynot = solve(prices,idx+1,1,0,dp);
            profit = max(profit,max(buy1,buynot));
        }
        else{
            int sell = prices[idx]+solve(prices,idx+2,1,0,dp);
            int sellnot = solve(prices,idx+1,0,1,dp);
            profit = max(profit,max(sell,sellnot));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int result  = solve(prices,0,1,0,dp);

        return result;
    }
};