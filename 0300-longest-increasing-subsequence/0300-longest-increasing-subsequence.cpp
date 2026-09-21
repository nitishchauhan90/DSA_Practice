class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        int ans = 1;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] > nums[i]) {
                ans = max(ans, 1 + solve(nums, j,dp));
            }
        }
       
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        vector<int>dp(nums.size()+1,-1);
        for(int i = 0; i < nums.size(); i++) {
            result = max(result, solve(nums, i,dp));
        }
        return result;
    }
};