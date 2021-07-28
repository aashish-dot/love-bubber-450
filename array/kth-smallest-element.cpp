//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int a[],int l,int r){
        int p=rand()%(r-l+1);
        swap(a[r],a[l+p]);
        int pivot=a[r];
        int i=l-1;
        for(int j=l;j<=r-1;j++){
            if(a[j]<pivot){
                i++;
                swap(a[i],a[j]);
            }
        }
        swap(a[i+1],a[r]);
        return i+1;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int ans;
        while(l<=r){
            int res=partition(arr,l,r);
        if(res==k-1)
        {
            ans=arr[res];
            break;
        }
        else if(res<k-1){
            l=res+1;
        }
        else
            r=res-1;
        
    }
    return ans;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends