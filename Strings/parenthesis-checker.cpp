#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool check(char a,char b){
        if(a=='('&&b==')'){
            return true;
        }
        else if(a=='['&&b==']')
            return true;
        else if(a=='{'&&b=='}')
            return true;
        else
            false;
    }
    
    bool ispar(string x)
    {
        // Your code here
        if(x.length()%2!=0){
            return false;
        }
        stack<char>s;
        for(int i=0;i<x.length();i++){
            if(x[i]=='('||x[i]=='{'||x[i]=='['){
                s.push(x[i]);
            }
            else{
                if(s.empty()){
                    return false;
                }
                char y=s.top();
                s.pop();
                if(check(y,x[i])==false)
                    return false;
            }
        }
        return true;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends