class Solution {
public:
    bool solve(vector<int>& nums,int target,vector<vector<int>>& dp,int i){ 
        if(target==0){
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool val = solve(nums,target-nums[i],dp,i+1) || solve(nums,target,dp,i+1);
        return dp[i][target] = val;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target + 1, -1));

        bool result = solve(nums,target,dp,0);
        return result;
    }
};