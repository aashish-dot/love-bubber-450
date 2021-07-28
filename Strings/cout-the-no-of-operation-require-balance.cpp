#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    int n=s.length();
    if(n==1)
        return -1;
    stack<char>st;
    int c=0;
    if(s[0]=='}'){
        c++;
    }
    st.push('{');
    for(int i=1;i<n;i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                c++;
                st.push('{');
            }
            else{
            char y=st.top();
            st.pop();
            if(y=='}'){
                c++;
            }
        }
        }
    }
    int r=st.size();
    if(r%2!=0)
        return -1;
    return c+((int)r/2.0);
}