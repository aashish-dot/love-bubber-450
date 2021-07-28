// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> gold)
    {
        // code here
        int goldTable[n][n];
	memset(goldTable, 0, sizeof(goldTable));

	for (int row=n-1; row>=0; row--)
	{
		for (int col=0; col<n; col++)
		{
			
			int down = (row==n-1)? 0: goldTable[row+1][col];

			
			int down_left = (row==n-1 || col==0)? 0:goldTable[row+1][col-1];

			
			int down_right = (row==n-1 || col==n-1)? 0:goldTable[row+1][col+1];

		
			goldTable[row][col] = gold[row][col] +max(down, max(down_left, down_right));
													
		}
	}

	// The max amount of gold collected will be the max
	// value in first column of all rows
	int res = goldTable[0][0];
	for (int i=0; i<n; i++)
		res = max(res, goldTable[0][i]);
	return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends