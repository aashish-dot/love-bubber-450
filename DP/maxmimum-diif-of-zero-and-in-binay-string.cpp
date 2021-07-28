#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n=S.length();
	    int a[n];
	    for(int i=0;i<n;i++){
	        if(S[i]-'0')
	            a[i]=-1;
	        else{
	            a[i]=1;
	        }
	    }
	    int cur=-1;
	    int mx=-1;
	    for(int i=0;i<n;i++){
	        cur=max(a[i],cur+a[i]);
	        mx=max(mx,cur);
	    }
	    return mx;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends