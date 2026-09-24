class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int majele = 0;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            if(count<=0){
                majele = nums[i];
                count = 1;

            }
            else if(majele==ele){
                count++;
            }
            else{
                count--;
            }
        }
        return majele;
    }
};