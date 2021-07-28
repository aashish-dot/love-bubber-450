
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        // code here
          int i,j,len;
    	int dpTrue[N][N],dpFalse[N][N];
    
    	for(i = 0;i < N;i+=2){
    		if(S[i]=='T'){
    			dpTrue[i][i]=1;
    			dpFalse[i][i]=0;
    		}else{
    			dpTrue[i][i]=0;
    			dpFalse[i][i]=1;
    		}
    	}
    	int x=2;
    	while(x < N){
    		for(i = 0;(i+x) < N;i+=2){
    			dpTrue[i][i+x] = dpFalse[i][i+x]=0;
    			for(j = i+1;j < (i+x);j+=2){
    				if(S[j]=='|'){
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpTrue[i][j-1]*dpTrue[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x] +
    									dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
    					dpFalse[i][i+x] = (dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x])%1003;								
    
    				}else if(S[j]=='&'){
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003 ;
    					dpFalse[i][i+x] =(dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x] +
    									dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
    				}else{
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpFalse[i][j-1]*dpTrue[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x])%1003 ;
    					dpFalse[i][i+x] = (dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x] +
    									dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003 ;
    				}
    			}
    		}
    	    x=x+2;
    	}
    	return dpTrue[0][N-1]%1003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends