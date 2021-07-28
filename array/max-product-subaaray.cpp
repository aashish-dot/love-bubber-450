#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long curmax=arr[0];
	    long long curmin=arr[0];
	    long long product=arr[0];
	    for(int i=1;i<n;i++){
	        int  p1=curmax*arr[i];
	        int  p2=curmin*arr[i];
	        curmax=max(arr[i],max(p1,p2));
	        curmin=min(arr[i],min(p1,p2));
	        product=curmax>product ? curmax :product;
	    }
	    return product;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
