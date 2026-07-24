class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count0 = 0;
        int multiply = 1;
        int zeroindex;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
                zeroindex = i;
            }
            else{
                multiply*=nums[i];
            }
            
        }
        vector<int>result(nums.size(),0);
        if(count0>1){
            return result;
        }
        else if(count0==0){
            for(int i=0;i<nums.size();i++){
                result[i] = multiply/nums[i];
            }
            return result;
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(i==zeroindex){
                    result[i] = multiply;
                }
            }
        }
        return result;
    }
};