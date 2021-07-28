#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
   	int dp[n][n];

	for(int i=0;i<n-1;i++)
	{
		dp[i][i+1]= max(arr[i],arr[i+1]);
	}

	for(int gap =3; gap<n; gap = gap + 2)
	{
		for(int i=0; i+gap<n; i++)
		{
			int j = gap + i;

			dp[i][j] = max((arr[i] + min(dp[i+2][j], dp[i+1][j-1])),
								(arr[j] + min(dp[i+1][j-1], dp[i][j-2])));
		}
	}

	return dp[0][n-1];
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends