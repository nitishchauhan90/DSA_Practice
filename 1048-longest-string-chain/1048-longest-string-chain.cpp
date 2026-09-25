class Solution {
public:

    bool ispreceder(string a, string b) {

        int m = a.size();
        int n = b.size();

        // b must be exactly one character longer
        if (n - m != 1) {
            return false;
        }

        int i = 0;
        int j = 0;

        while (i < m && j < n) {

            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i == m;
    }

    int solve(vector<string>& words, int prev, int curr,
              vector<vector<int>>& dp) {

        if (curr >= words.size()) {
            return 0;
        }

        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }

        // Don't take curr
        int not_taken = solve(words, prev, curr + 1, dp);

        // Take curr
        int taken = 0;

        if (prev == -1 || ispreceder(words[prev], words[curr])) {
            taken = 1 + solve(words, curr, curr + 1, dp);
        }

        return dp[prev + 1][curr] = max(taken, not_taken);
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](string& a, string& b) {
                 return a.size() < b.size();
             });

        int n = words.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n, -1)
        );

        return solve(words, -1, 0, dp);
    }
};