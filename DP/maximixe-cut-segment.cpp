#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10001];
    int check(int n,int x,int y,int z){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
    if(n>=x) op1=check(n-x,x,y,z);
    if(n>=y) op2=check(n-y,x,y,z);
    if(n>=z) op3=check(n-z,x,y,z);
    return dp[n]=1+max(op1,max(op2,op3));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        int a=check(n,x,y,z);
        if(a<0)
            return 0;
        return a;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends