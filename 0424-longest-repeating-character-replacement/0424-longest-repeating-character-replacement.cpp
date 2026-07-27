class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>map;
        int i =0 ;
        int j =0;
        int maxi = 0;
        int ans = 0;
        while(i<s.size()){
            map[s[i]]++;
            maxi = max(maxi,map[s[i]]);
            if((i-j+1)-maxi>k){
                map[s[j]]--;
                j++;
            }
            else{
                ans = max(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};