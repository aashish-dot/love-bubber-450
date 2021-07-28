#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp[1001][1001];
    int solve(string wild,string pattern,int i,int j){
        if(i==-1&&j==-1) return 1;
        if(j==-1){
            for(int k=0;k<i;k++){
                if(wild[k]!='*')return 0;
            }
            return 1;
        }
        if(i==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(wild[i]==pattern[j]||wild[i]=='?')return dp[i][j]=solve(wild,pattern,i-1,j-1);
        if(wild[i]=='*')
        {
            return dp[i][j]=(solve(wild,pattern,i-1,j)||solve(wild,pattern,i,j-1));
        }
        return dp[i][j]=0;
    }
    bool match(string wild, string pattern)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(wild,pattern,wild.length()-1,pattern.length()-1);
        
    }
};
