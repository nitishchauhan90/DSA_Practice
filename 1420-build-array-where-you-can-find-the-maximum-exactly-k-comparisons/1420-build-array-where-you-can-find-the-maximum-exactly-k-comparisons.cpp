class Solution {
public:
    int N,M,K;
    int mod = 1e9+7;
    int t[51][51][101];
    int solve(int idx,int searchcost,int maxsofar){
        if(idx==N){
            if(searchcost==K){
                return 1;
            }
            return 0;
        }
        if(t[idx][searchcost][maxsofar]!=-1){
            return t[idx][searchcost][maxsofar];
        }
        int result = 0;
        for(int i=1;i<=M;i++){
            if(i>maxsofar){
                result = (result + solve(idx+1,searchcost+1,i))%mod;
            }
            else{
                result = (result + solve(idx+1,searchcost,maxsofar))%mod;
            }
        }
        return t[idx][searchcost][maxsofar] = result%mod;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        int result = solve(0,0,0);
        return result;
    }
};