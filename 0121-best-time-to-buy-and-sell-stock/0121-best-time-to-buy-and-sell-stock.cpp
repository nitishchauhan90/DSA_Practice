class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>suffix(prices.size());
        int maxi = prices[prices.size()-1];
        for(int i=prices.size()-1;i>=0;i--){
            if(maxi<prices[i]){
                maxi = prices[i];
                suffix[i] = maxi;
            }
            else{
                suffix[i] = maxi;
            }
        }
        int result = 0;
        for(int i=0;i<prices.size();i++){
            int diff = suffix[i]-prices[i];
            result = max(result,diff);
        }
        return result;
    }
};