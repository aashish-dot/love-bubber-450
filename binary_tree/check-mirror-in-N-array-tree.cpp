//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
          vector<int> g1[100005];
		vector<int> g2[100005];
		
		for(int i=0; i<2*e; i+=2)
		{
			int x = A[i];
			int y = A[i+1];
			g1[x].push_back(y);
		}
		
		for(int i=0; i<2*e; i+=2)
		{
			int x = B[i];
			int y = B[i+1];
			g2[x].push_back(y);
		}
		
		stack<int> s;
		queue<int> q;
		
		s.push(1);
		q.push(1);
		bool f=0;
		while(!s.empty() and !q.empty())
		{
			int s1 = s.top();
			s.pop();
			int s2 = q.front();
			q.pop();
			
			if(s1!=s2)
			{
				f=1;
				break;
			}
			
			for(auto i = 0; i<g1[s1].size(); i++)
				s.push(g1[s1][i]);
				
			vector<int> k;
			while(!q.empty())
			{
    			k.push_back(q.front());
    			q.pop();
			}
			
			for(auto i=0; i<g2[s2].size(); i++)
				q.push(g2[s2][i]);
				
			for(int i=0; i<k.size(); i++)
			    q.push(k[i]);
		}
		
		if(s.empty() and q.empty() and !f)
			return 1;
		else 
		    return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends