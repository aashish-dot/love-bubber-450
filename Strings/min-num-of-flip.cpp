#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int c1=0,c2=0;
    
        for(int i=0;i<s.length();i++){
            if(i%2!=0&&s[i]=='1'||i%2==0&&s[i]=='0'){
                continue;
            }
            else{
                c1++;
            }
        
    }
    
    for(int i=0;i<s.length();i++){
        if(i%2==0&&s[i]=='1'||i%2!=0&&s[i]=='0'){
                continue;
            }
            else{
                c2++;
            }
        }
    return min(c1,c2);
}