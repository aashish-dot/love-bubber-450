#include<bits/stdc++.h>
using namespace std;
bool isfeasible(int a[],int n,int m,int ans){
    int sum=0;
    for(int i=0;i<n;i++){
    if(a[i]>ans){
        sum=sum+(a[i]-ans);
    if(sum>=m)
        return true;
    }
   
    }
    return false;

}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    sort(a,a+n);
    int l=0,h=a[n-1];
    int ans =-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(isfeasible(a,n,m,mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;

}