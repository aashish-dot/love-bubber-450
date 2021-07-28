//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        if(n==1)
            return {1};
        vector<long long>left(n);
        vector<long long>right(n);
        vector<long long>ans;
        
        left[0]=nums[0];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i];
        }
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i];
        }
        ans.push_back(right[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(left[i-1]*right[i+1]);
            //cout<<left[i-1]*right[i+1]<<" ";
        }
        ans.push_back(left[n-2]);
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends