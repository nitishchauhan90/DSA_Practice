class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int result = 0;
        while(i<j){
            result = max(result,(j-i)*min(height[i],height[j]));
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return result;
    }
};