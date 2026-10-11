class Solution {
public:
    int t[101][101][201];
    bool solve(int n,int m,int p,int i,int j,int k,string s1, string s2, string s3){
        if(i==n&&j==m&&k==p){
            return true;
        }
        if(k>=p){
            return false;
        }
        if(t[i][j][k]!=-1){
            return t[i][j][k];
        }

        bool result = false;
        if(s1[i]==s3[k]){
            result = solve(n,m,p,i+1,j,k+1,s1,s2,s3);
        }
        if(s2[j]==s3[k]){
            result = result || solve(n,m,p,i,j+1,k+1,s1,s2,s3);
        }
        return t[i][j][k]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        memset(t,-1,sizeof(t));
        if((n+m)!=p){
            return false;
        }
        bool result  = solve(n,m,p,0,0,0,s1,s2,s3);
        return result;
    }
};