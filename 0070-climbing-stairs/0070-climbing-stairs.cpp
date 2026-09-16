
class Solution {
public:
    
    int solve(int n,int& count,int steps,vector<int>& dp){
        if(steps>n){
            return 0;
        }
        if(steps==n){
            count+=1;
            return 1;
        }
        if(dp[steps]!=-1){
            return dp[steps];
        }
        dp[steps] = solve(n,count,steps+1,dp)+solve(n,count,steps+2,dp);
        return dp[steps];
    }
    int climbStairs(int n) {
        int count = 0;
        vector<int> dp(n + 1, -1);
        return solve(n,count,0,dp);

    }
}; 