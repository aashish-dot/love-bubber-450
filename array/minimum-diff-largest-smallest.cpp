//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getMinDiff(int a[], int n, int k) {
        // code hereint 
    if(n==1)
        return 0;
    sort(a,a+n);
    int ans=a[n-1]-a[0];
    int small=a[0]+k;
    int big=a[n-1]-k;
    
    if(small>big)
        swap(small,big);
    for(int i=1;i<n-1;i++){
        int sub=a[i]-k;
        int add=a[i]+k;
        if(sub>=small||add<=big)
            continue;
    if(big-sub<=add-small)
        small=sub;
    else
        big=add;
        
    }
    ans=min(ans,big-small);
        
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends