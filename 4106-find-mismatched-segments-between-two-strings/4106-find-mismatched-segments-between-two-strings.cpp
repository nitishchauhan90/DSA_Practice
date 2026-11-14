class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>result;
        int l=0,r=0;
        while (r < s1.size()) {

            if (s1[r] == s2[r]) {

                if (l < r) {

                    result.push_back({

                        s1.substr(l, r - l),

                        s2.substr(l, r - l)

                    });
                }
                l = r + 1;
            }
            r++;
        }
        if(l<s1.size()){
            result.push_back({s1.substr(l),s2.substr(l)});
        }
        return result;
    }
};