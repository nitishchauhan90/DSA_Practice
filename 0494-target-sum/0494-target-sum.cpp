class Solution {
public:
    unordered_map<string, int> dp;
    int solve(vector<int>&nums,int target,int idx,int sum){
        if(idx == nums.size()) {
            return sum == target;
        }
         string key = to_string(idx) + "," + to_string(sum);

        if (dp.count(key)) {

            return dp[key];

        }
        int positive = solve(nums,target,idx+1,sum+nums[idx]);
        int negative = solve(nums,target,idx+1,sum-nums[idx]);
        return dp[key] = positive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        int result = solve(nums,target,0,0);
        return result;
    }
};