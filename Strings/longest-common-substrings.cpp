#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output=strs[0];
        for(int i=1;i<strs.size();i++){
            string x=strs[i];
            if(x.length()<output.length()){
                output=output.substr(0,x.length());
            }
            for(int j=0;j<x.length();j++){
                if(output[j]!=x[j]){
                    output=output.substr(0,j);
                    break;
                }
            }
            
        }
        return output;
    }
};