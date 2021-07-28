// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

/* This function returns
median of ar1[] and ar2[].
Assumptions in this function:
Both ar1[] and ar2[]
are sorted arrays
Both have n elements */
int getMedian(int ar1[], int ar2[], int n)
{
	int j = 0;
	int i = n - 1;
	while (ar1[i] > ar2[j] && j < n && i > -1)
		swap(ar1[i--], ar2[j++]);
	sort(ar1, ar1 + n);
	sort(ar2, ar2 + n);
	return (ar1[n - 1] + ar2[0]) / 2;
}

// Driver Code
int main()
{
	int ar1[] = { 1, 12, 15, 26, 38 };
	int ar2[] = { 2, 13, 17, 30, 45 };

	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	if (n1 == n2)
		cout << "Median is " << getMedian(ar1, ar2, n1);
	else
		cout << "Doesn't work for arrays"
			<< " of unequal size";
	getchar();
	return 0;
}

// This code is contributed
// by Lakshay
