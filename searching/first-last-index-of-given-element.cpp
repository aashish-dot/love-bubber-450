#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends

int first(int a[],int n,int x){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]<x)
            l=m+1;
        else{
            if(a[m]==x)
            {
                ans=m;
                r=m-1;
            }
            else{
                r=m-1;
            }
        }
    }
    return ans;
}
int last(int a[],int n,int x){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]>x)
            r=m-1;
        else{
            if(a[m]==x)
            {
                ans=m;
                l=m+1;
            }
            else{
                l=m+1;
            }
        }
    }
    return ans;
}
vector<int> find(int a[], int n , int x )
{
    // code here
    vector<int>v;
    v.push_back(first(a,n,x));
    v.push_back(last(a,n,x));
    return v;
}