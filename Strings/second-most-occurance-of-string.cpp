#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>s;
        
        for(int i=0;i<n;i++){
            s[arr[i]]++;
            
        }
        int max1=INT_MIN,max2=INT_MIN;
       
        for(auto x:s){
            if(max1<x.second){
                max2=max1;
                max1=x.second;
                
            }
            else if(x.second>max2 && max1!=x.second){
                max2=x.second;
            }
        }
        for(auto x:s){
            if(x.second==max2){
                return x.first;
            }
            
        }
        return "";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends