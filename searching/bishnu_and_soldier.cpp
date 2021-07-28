#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    sort(a,a+n);
     int c[n],sum=0;
    for(int i=0; i<n; i++)
    {
        sum+= a[i]; c[i]= sum;
    }
    int q; cin>>q;
    int b[q];
    for(int i=0; i<q; i++)
    cin>>b[i];
    for(int i=0; i<q; i++)
    {
        int j;
        for( j=0; j<n; j++)
        {
            if(a[j]>b[i])
            break;
        }
        cout<< j << " "<< c[j-1]<<"\n";
    }
    return 0;
    
 
}