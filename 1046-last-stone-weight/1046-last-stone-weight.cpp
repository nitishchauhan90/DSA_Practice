class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap;
        for(int i=0;i<stones.size();i++){
            maxheap.push(stones[i]);
        }

        if(maxheap.size()<2){
            return maxheap.top();
        }
        while(maxheap.size()>=2){
            int max1 = maxheap.top();
            maxheap.pop();
            int max2 = maxheap.top();
            maxheap.pop();
            if(max1==max2){
                continue;
            }
            maxheap.push(max1-max2);
        }
        return maxheap.empty() ? 0 : maxheap.top();
    }
};