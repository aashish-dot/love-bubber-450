#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>vis(26,0);
		    vector<char>v;
		    string ans="";
		    int n=A.length();
		    for(int i=0;i<n;i++){
		        if(vis[A[i]-'a']==0){
		            v.push_back(A[i]);
		        }
		        vis[A[i]-'a']++;
		        int f=0;
		        int m=v.size();
		        for(int j=0;j<m;j++){
		            if(vis[v[j]-'a']==1){
		                ans.push_back(v[j]);
		                f=1;
		                break;
		            }
		        }
		        if(f==0){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends