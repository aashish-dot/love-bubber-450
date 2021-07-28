#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[201][201];
    int fill(int e,int f){
        if(f==0||f==1)
            return f;
        if(e==1)
            return f;
        if(t[e][f]!=-1)
            return t[e][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int left,right;
            if(t[e-1][k-1]!=-1)
                left=t[e-1][k-1];
            else
                 left=fill(e-1,k-1);
            if(t[e][f-k]!=-1)
                right=t[e][f-k];
            else
                 right=fill(e,f-k);
            int temp=1 + max(left,right);
            mn=min(mn,temp);
        }
        return t[e][f]=mn;
    }
    int eggDrop(int n, int k) 
    { memset(t,-1,sizeof(t));
        return fill(n,k);
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends