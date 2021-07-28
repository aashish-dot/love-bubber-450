#include<bits/stdc++.h>
using namespace std;
bool check(long long int a[],int n,long long int d,int c){
    int l=1;
	int lastpos=a[0];
    for(int j=1;j<n;j++){
        if(a[j]-lastpos>=d){
            l++;
            lastpos=a[j];
            if(l==c)
                return true;
    
    }
}
        return false;
}
int main() {
int t;
cin>>t;
while(t--){
    int n,c;
    cin>>n>>c;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long int max=a[n-1]-a[0];
    long long int min=0;
    long long int ans=0;
    while(min<=max){
        long mid=min+(max-min)/2;
        if(check(a,n,mid,c)){
            ans=mid;
            min=mid+1;}
        else{
            max=mid-1;
        }
        
    }
    cout<<ans<<endl;
}
	// Write your code here
}