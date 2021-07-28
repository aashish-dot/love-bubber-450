#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int minv=prices[0];
        for(int i=1;i<prices.size();i++){
            res=max(res,prices[i]-minv);
            minv=min(minv,prices[i]);
            
        }
        return res;
    }
        
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>prices(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            prices.push_back(x);
            

        }
        Solution ob;
            cout<<ob.maxProfit(prices);
    }
    return 0;
}