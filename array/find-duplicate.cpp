#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int turtle=nums[0];
        int rabbit=nums[0];
        do{
            turtle=nums[turtle];
            rabbit=nums[nums[rabbit]];
        }while(turtle!=rabbit);
        turtle=nums[0];
        while(turtle!=rabbit){
            turtle=nums[turtle];
            rabbit=nums[rabbit];
        }
        return rabbit;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums.push_back(x);
        }
        Solution ob;
        cout<<ob.findDuplicate(nums);

    }
    return 0;
}