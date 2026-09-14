class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int> nums,int i,vector<int>arr){
        if(i>=nums.size()){
            result.push_back(arr);
            return;
        }
        vector<int> newarr = arr;

        newarr.push_back(nums[i]);
        solve(result,nums,i+1,newarr);
        solve(result,nums,i+1,arr);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>arr;
        solve(result,nums,0,arr);

        return result ;
    }
};