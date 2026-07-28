class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=0;
                st.push(i);
            }
            else{
                int count = 1;
                while(!st.empty()&&temperatures[st.top()]<=temperatures[i]){
                    count++;
                    st.pop();
                }
                if(st.empty()){
                    result[i]=0;
                    st.push(i);
                }
                else{
                    result[i] = st.top()-i;
                    st.push(i);
                }
            }
        }
        return result;
    }
};