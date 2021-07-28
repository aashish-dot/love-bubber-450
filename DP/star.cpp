#include<bits/stdc++.h>
using namespace std;
string longestpalind(string s){
    int n=s.size();
    int start=0,end=1,l,h;
    for(int i=1;i<n;i++){
        //for odd
        l=i-1;
        h=i;
        while(l>=0&&h<n&&s[l]==s[h]){
            if(h-l+1>end){
                start=l;
                end=h-l+1;
                
            }
            l--;
                h++;
        }

        //for even
          l=i-1;
        h=i+1;
        while(l>=0&&h<n&&s[l]==s[h]){
            if(h-l+1>end){
                start=l;
                end=h-l+1;
                
            }
            l--;
                h++;
            
        }

    }
    return s.substr(start,end);
}
int main(){
    string s;
    cin>>s;
    cout<<"palindromic  "<<longestpalind(s)<<endl;
    return 0;
}