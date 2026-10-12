class Solution {
public:
    int dp[1001][1001];
    int solve(string& s, string& t,int i,int j){
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result = solve(s,t,i+1,j);
        if(s[i]==t[j]){
            result += solve(s,t,i+1,j+1);
        }
        return dp[i][j] = result;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        int result = solve(s,t,0,0);
        return result;
    }
};