// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int dp[1001][1001];
    int func(int i,int j,string s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
             dp[i][j]=func(i+1,j,s)+func(i,j-1,s)+1;
        }
        else{
             dp[i][j]=func(i+1,j,s)+func(i,j-1,s)-func(i+1,j-1,s);
        }
        return dp[i][j];
        
    }
    
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.length();
       dp[n][n];
       memset(dp,-1,sizeof(dp));
       return func(0,n-1,str);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends