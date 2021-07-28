// CPP program to find number of subarrays having
// product less than k.
#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.
int productSubSeqCount(vector<int> &arr, int k)
{
	int n = arr.size();
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
	
			// number of subsequence using j-1 terms
			//dp[i][j] = dp[i][j - 1];

			// if arr[j-1] > i it will surely make product greater
			// thus it won't contribute then
			if (arr[i - 1] <= j && arr[i - 1] > 0)
				dp[i][j] = dp[i-1][j/arr[i-1]] + dp[i-1][j]+1;
            else
                dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][k];
}

// Driver code
int main()
{
	vector<int> A;
	A.push_back(4);
	A.push_back(8);
	A.push_back(7);
	A.push_back(2);
	int k = 50;
	cout << productSubSeqCount(A, k) << endl;
}
