class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> map;
    for(auto x:nums){
        if(map.count(x))return true;
        map[x]++;
    }    
    return false;
    }
};