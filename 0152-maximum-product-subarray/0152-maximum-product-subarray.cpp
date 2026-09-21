class Solution {
public:
    // void solve(vector<int>& nums,int idx , int& product,int pp){
    //     if(idx >=nums.size()){
    //         return ;
    //     }
    //    pp *= nums[idx];
    //     product = max(product, pp);
    //     solve(nums, idx + 1, product, pp);
    //     solve(nums, idx + 1, product, 1);
    // }
    int maxProduct(vector<int>& nums) {
        // int product = INT_MIN ;
        // solve(nums,0,product,1);
        // return product;


        int n = nums.size();

        vector<int> maxDP(n);

        vector<int> minDP(n);

        maxDP[0] = nums[0];

        minDP[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            int curr = nums[i];

            maxDP[i] = max({

                curr,

                curr * maxDP[i - 1],

                curr * minDP[i - 1]

            });

            minDP[i] = min({

                curr,

                curr * maxDP[i - 1],

                curr * minDP[i - 1]

            });

            ans = max(ans, maxDP[i]);

        }

        return ans;
    }
};