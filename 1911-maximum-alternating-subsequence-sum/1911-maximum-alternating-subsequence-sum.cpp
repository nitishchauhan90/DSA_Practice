class Solution {
public:
    long long solve(vector<int>& nums,int idx,vector<vector<long long>>&dp,bool flag){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        long long skip = solve(nums,idx+1,dp,flag);
        long long val = nums[idx];
        if(flag==false){
            val = -val;
        }
        long long take = solve(nums,idx+1,dp,!flag)+val;
        return dp[idx][flag] = max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size()+1,vector<long long>(2,-1));
        long long result = solve(nums,0,dp,true);
        return result;
    }
};