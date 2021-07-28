#include<bits/stdc++.h>
using namespace std;
void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    // output is passed with including
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);
 
    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}
int main(){
    int t;
    while(t--)
    {
        string s;
        cin>>s;
        printSubsequence("",s);
        return 0;
    }
}