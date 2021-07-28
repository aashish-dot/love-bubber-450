#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[a[i]]=0;
    }
    int c1=1;
    
    for(int i=0;i<n;i++){
    if(m[a[i]]==0){
        m[a[i]]=1;
        int c=a[i]+1;
        int c2=1;
        while(m.find(c)!=m.end()){
            m[c]=1;
            c++;
            
            c2++;
            c1=max(c2,c1);
        }
        c=a[i]-1;
        while(m.find(c)!=m.end()){
             m[c]=1;
            c--;
           
            c2++;
            c1=max(c2,c1);
        }
        //cout<<c2<<" ";
            
    }
    }
    return c1;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends