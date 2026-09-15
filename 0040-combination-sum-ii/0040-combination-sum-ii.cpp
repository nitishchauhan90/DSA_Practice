class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>& candidates,int target,int start,vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                 continue;

            if (candidates[i] > target)
                break;
            current.push_back(candidates[i]);
            solve(result, candidates, target - candidates[i],i+1, current);
            current.pop_back();

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(result, candidates, target, 0, current);
        return result;
    }
};