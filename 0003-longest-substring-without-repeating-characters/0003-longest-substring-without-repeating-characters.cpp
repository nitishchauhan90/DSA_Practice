class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int result = 0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])==0){
                st.insert(s[i]);
                result = max(result ,i-j+1);
            }
            else{
                while(st.find(s[i])!=st.end()&&j<i){
                    st.erase(s[j]);
                    j++;      
                }
                st.insert(s[i]);
            }
            
           
        }
        return result;
    }
};