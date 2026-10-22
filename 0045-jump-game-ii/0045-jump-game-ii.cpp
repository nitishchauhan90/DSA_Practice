class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();

        if (i == n - 1) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int result = INT_MAX;

        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            int steps = solve(nums, i + j, dp);

            if (steps != INT_MAX) {
                result = min(result, 1 + steps);
            }
        }

        return dp[i] = result;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};