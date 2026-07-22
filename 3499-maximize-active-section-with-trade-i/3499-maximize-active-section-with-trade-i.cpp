class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev = 0;
        int result = 0;
        int count1 = 0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'){
                count1++;
                i++;
            }
            else{
                int curr = 0;
                while(s[i]=='0'){
                    curr++;
                    i++;
                }
                if(prev>0){
                    result = max(result ,(curr+prev));
                }
                prev = curr;
            }
        }
        return result+count1;
    }
};