
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here  
        int cursum=0,min_len=n+1;
        int s=0,e=0;
        while(e<n){
            while(cursum<=x&&e<n){
                cursum+=arr[e++];
            }
            while(cursum>x&&s<e){
                min_len=min(min_len,e-s);
                cursum-=arr[s++];
            }
        }
        if(min_len>n)
            return 0;
        return min_len;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends