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
    void solve(string& s, int& result, int start) {
        if (start >= s.size()) {
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                result+=1;
            }
        }
        solve(s, result, start + 1);
    }
    int countSubstrings(string s) {
        int result = 0;
        solve(s, result, 0);
        return result;
    }
};