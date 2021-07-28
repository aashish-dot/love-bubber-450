 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    int len=0;
	    int lps[s.length()]={0};
	    lps[0]=0;
	    int i=1;
	    while(i<s.length()){
	        if(s[i]==s[len]){
	            len++;
	          
	            lps[i]=len;
	              i++;
	        }
	        else{
	            if(len!=0)
	                len=lps[len-1];
	            else{
	                
	                i++;
	            }
	        }
	    }
	    // Your code goes here
	    
	    return lps[s.length()-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends