class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string& s, string& result, int start) {
        if (start >= s.size()) {
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                if (end - start + 1 > result.size()) {
                    result = s.substr(start, end - start + 1);
                }
            }
        }
        solve(s, result, start + 1);
    }
    string longestPalindrome(string s) {
        string result = "";
        solve(s, result, 0);
        return result;
    }

};