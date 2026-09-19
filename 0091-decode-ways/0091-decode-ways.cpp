class Solution {
public:

    void solve(string s, int& count, int n,unordered_map<string, int>& dp) {

        if (s.size() == 0) {
            count += 1;
            return;
        }
        if (dp.find(s) != dp.end()) {
            count += dp[s];
            return;
        }

        int before = count;

        for (int i = 0; i < 2 && i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            if (stoi(part) <= 26 &&
                stoi(part) > 0 &&
                part[0] != '0') {

                solve(s.substr(i + 1), count, n, dp);
            }
        }
        dp[s] = count - before;
    }

    int numDecodings(string s) {

        if (s[0] == '0') {
            return 0;
        }

        if (s.size() == 1) {
            return 1;
        }

        int count = 0;
        int n = s.size();

        unordered_map<string, int> dp;

        solve(s, count, n, dp);

        return count;
    }
};