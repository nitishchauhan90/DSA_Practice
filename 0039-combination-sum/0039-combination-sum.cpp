class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>ans,vector<int>candidates,int target,int i,int sum){
        if(i>=candidates.size()){
            if(sum==target){
                result.push_back(ans);
            }
            return;
        }
        if(sum>target){
            return;
        }
        if(sum==target){
            result.push_back(ans);
            return;
        }
        vector<int> temp = ans;
        temp.push_back(candidates[i]);
        solve(result,temp,candidates,target,i,sum+candidates[i]);
        // solve(result,temp,candidates,target,i+1,sum+candidates[i]);
        solve(result,ans,candidates,target,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;

        solve(result,ans,candidates,target,0,0);

        return result;
    }
};