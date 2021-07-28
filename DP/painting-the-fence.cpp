#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int m=1000000007;
    long long countWays(int n, int k){
        // code here
        if(n==0)return 0;
        if(n==1)return k;
        long long int same=k%m;
        long long int diff=k*(k-1)%m;
        for(int i=3;i<=n;i++){
            long long int pre=diff%m;
            diff=((((same+diff)%m)*(k-1))%m)%m;
            same=pre;
        }
        return (same+diff)%m;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends