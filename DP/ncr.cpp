// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int m=1000000007;
    int nCr(int n, int r){
        // code here
    int c[r+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,r);j>0;j--){
            c[j]=(c[j]%m+c[j-1]%m)%m;
        }
    }
    return c[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends