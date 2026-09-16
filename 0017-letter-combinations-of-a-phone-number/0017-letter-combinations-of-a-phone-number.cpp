class Solution {
public:
    vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
    void solve(string digits,vector<string>&result,string s,int idx){
        if(idx>=digits.size()){
            result.push_back(s);
            return;
        }
        int dig = digits[idx] - '0';
        for(int i=0;i<mp[dig].size();i++){
            string nw = mp[dig];
            s+=nw[i];
            solve(digits,result,s,idx+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        string s="";
        solve(digits,result,s,0);
        return result;
    }
};