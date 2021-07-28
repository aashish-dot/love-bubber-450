// C++ program to find the maximum sum such that
// no three are consecutive using recursion.
#include<bits/stdc++.h>
using namespace std;

int arr[] = {100, 1000, 100, 1000, 1};
int sum[10000];

// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSumWO3Consec(int n)
{
	if(sum[n]!=-1)
	return sum[n];
	
	//Base cases (process first three elements)
	
	if(n==0)
	return sum[n] = 0;
	
	if(n==1)
	return sum[n] = arr[0];
	
	if(n==2)
	return sum[n] = arr[1]+arr[0];
	
	// Process rest of the elements
	// We have three cases
	return sum[n] = max(max(maxSumWO3Consec(n-1),
					maxSumWO3Consec(n-2) + arr[n]),
					arr[n] + arr[n-1] + maxSumWO3Consec(n-3));
	
	
}

// Driver code
int main()
{
	
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(sum,-1,sizeof(sum));
	cout << maxSumWO3Consec(n);

// this code is contributed by Kushdeep Mittal
	return 0;
}
