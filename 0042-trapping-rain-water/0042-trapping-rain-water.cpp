class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix(height.size()),suffix(height.size());
        int max = height[0];
        int maxr = height[height.size()-1];
        for(int i =0;i<height.size();i++){
            if(max<height[i]){
                max = height[i];
                prefix[i]=max;
            }
            else{
                prefix[i]=max;
            }

        }
        for(int j=height.size()-1;j>=0;j--){
            if(maxr<height[j]){
                maxr = height[j];
                suffix[j] = maxr;
            }
            else{
                suffix[j] = maxr;
            }
        }
        int result = 0;
        for(int i = 0;i<height.size();i++){
            int h = min(prefix[i],suffix[i]);
            result += (h-height[i]);
        }
        return result;
    }
};