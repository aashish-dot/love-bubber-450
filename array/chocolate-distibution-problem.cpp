#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long k){
    //code
    sort(a.begin(),a.end());
  
	    long long res=INT_MAX;
	    for(long i=0;i<n-k+1;i++){
	        res=min(res,a[i+k-1]-a[i]);
	    }
	    //cout<<res<<endl;
    
    return res;
    }
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends