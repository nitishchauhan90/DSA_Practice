class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] = max(nums[i]+solve(nums,i+2,dp),solve(nums,i+1,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);

    }
};