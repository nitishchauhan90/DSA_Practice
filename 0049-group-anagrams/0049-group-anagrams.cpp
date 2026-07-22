class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> map;
    for(auto x:strs)
    {
        string y=x;
        sort(y.begin(),y.end());
        map[y].push_back(x);
    } 
    vector<vector<string>> ans;
    for(auto x:map)ans.push_back(x.second);
    return ans;  
    }
};