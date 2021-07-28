
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kadence(vector<int>&a,int n){
      int mx=a[0];
      int cur=a[0];
      for(int i=1;i<n;i++){
          cur=max(a[i],cur+a[i]);
          mx=max(mx,cur);
      }
      return mx;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ma=INT_MIN;
        for(int i=0;i<R;i++){
            vector<int>ans(C);
            for(int j=i;j<R;j++){
                for(int col=0;col<C;col++){
                    ans[col]+=M[j][col];
                }
                int temp=kadence(ans,C);
                ma=max(ma,temp);
            }
        }
       return ma; 
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends