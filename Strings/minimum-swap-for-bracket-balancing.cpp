#include<bits/stdc++.h>
using namespace std;  
  int minimumNumberOfSwaps(string s){
        // code here 
        int n=s.size();
        int countleft=0,countright=0;
        int swap=0,imbalance=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                countleft++;
                if(imbalance>0){
                    swap+=imbalance;
                    imbalance--;
            }
            }
            else{
                countright++;
                
                imbalance=countright-countleft;
            }
        }
        return swap;
    }  int minimumNumberOfSwaps(string s){
        // code here 
        int n=s.size();
        int countleft=0,countright=0;
        int swap=0,imbalance=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                countleft++;
                if(imbalance>0){
                    swap+=imbalance;
                    imbalance--;
            }
            }
            else{
                countright++;
                
                imbalance=countright-countleft;
            }
        }
        return swap;
    }