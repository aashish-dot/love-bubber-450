#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>&a) {
        int n=a.size();
    
        int i=n-2;
          
            
         while (i >= 0 && a[i + 1] <= a[i]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (a[j] <= a[i]) {
                j--;
            }
            swap(a[i],a[j]);
        }
        reverse(a.begin()+i+1,a.end());
        
    }
};