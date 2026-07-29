class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        if(h==piles.size()){
            return *max_element(piles.begin(),piles.end());
        }
        int i=1;
        while(i<maxi){
            int mid = i + (maxi-i)/2;
            int calc = 0;
            for(int p =0;p<piles.size();p++){
                int qu = piles[p]/mid;
                if(qu==0){
                    calc+=1;
                }
                else{
                    calc+=piles[p]/mid;
                    if(piles[p]%mid>0){
                        calc+=1;
                    }
                }
            }
            if(calc<=h){
                maxi = mid;
            }
            else{
                i = mid+1;
            }
        }
        return i;
    }
};