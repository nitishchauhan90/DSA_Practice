class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int> nums,int first,vector<int>arr){
        result.push_back(arr);
        for(int i=first;i<nums.size();i++){
            arr.push_back(nums[i]);
            solve(result,nums,i+1,arr);
            arr.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>arr;
        solve(result,nums,0,arr);

        return result ;
    }
};