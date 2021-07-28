//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


//User function Template for C++


// Return the maximum water that can be stored 
  int maxWater(int height[], int n) 
    { 
    	int maximum = 0; 
    
    	//using two pointers that point at first and last building respectively. 
    	int i = 0, j = n - 1; 
    		    
    	while (i < j) 
    	{ 
    		//if height at index i is less than height at index j, updating 
    		//maximum water stored so far and incrementing i.
    		if (height[i] < height[j]) 
    		{ 
    			maximum = max(maximum, (j-i-1) * height[i]); 
    			i++; 
    		} 
            //else if height at index i is more than height at index j,  
    		//updating maximum water stored so far and decrementing j.
    		else if (height[j] < height[i]) 
    		{ 
    			maximum = max(maximum, (j-i-1) * height[j]); 
    			j--; 
    		} 
    		//else updating maximum water stored so far and both pointers.
    		else
    		{ 
    			maximum = max(maximum, (j-i-1) * height[i]); 
    			i++; 
    			j--; 
    		} 
    	} 
        //returning the result.
    	return maximum; 
    }




// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        
        cout<<(maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends