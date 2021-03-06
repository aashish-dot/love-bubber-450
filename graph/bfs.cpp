#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    void bfs(int V, vector<int> adj[],vector<int>&res,int vis[],int s){
        vis[s]=1;
        queue<int>q;
        q.push(s);
       
        while(!q.empty()){
            int u=q.front();
             res.push_back(u);
            q.pop();
            for(auto x:adj[u]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push(x);
                }
            }
            
        }
    }
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int>res;
	    int vis[V]={0};
	    
	           bfs(V,adj,res,vis,0);
	        
	    
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends