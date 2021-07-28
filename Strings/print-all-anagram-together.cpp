//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
   vector<vector<string> > result;

    // hash map to maintain groups of anagrams
    unordered_map <string,vector<string> > umap; 
    
    for(int i =0; i<string_list.size(); i++ )
    {
        string s = string_list[i];
     
        // sort each string
        sort(s.begin(),s.end());
        
        // add original string to corresponding sorted string in hash map
        umap[s].push_back(string_list[i]);
    }
    for(auto itr= umap.begin(); itr!=umap.end(); itr++)
        result.push_back(itr->second);
    
    return result;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends