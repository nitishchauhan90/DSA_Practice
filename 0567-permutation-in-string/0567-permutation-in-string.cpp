class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>dict(26);
        if(s1.size()>s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            dict[s1[i]-'a']++;
        }
        int j=0;
        vector<int>dict2(26);
        for(int i=0;i<s2.size();i++){
            dict2[s2[i]-'a']++;
            if((i-j+1)>s1.size()){
                dict2[s2[j]-'a']--;
                j++;
            }
            if((i-j+1)==s1.size()){
                if(dict2==dict){
                    return true;
                }
            }

        }
        return false;
    }
};