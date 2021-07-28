#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int n,c;
        cin>>n>>c;
        vector<pair<int,int>>v;
       
        int a=1,b=INT_MAX;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
            a=max(a,x);
            b=min(b,y);
        }
        for(int i=a;i<=b;i++){
            int l=v.size();
            for(int j=0;j<l;j++){
                if(v[j].first<i&&v[j].second>i){
                    v.push_back({i,v[j].second});
                    v[j].second=i;
                    
                }
            }
        }
        
       
        cout<<"Case #"<<k<<": "<<v.size()<<endl;;
    }
    return 0;
}