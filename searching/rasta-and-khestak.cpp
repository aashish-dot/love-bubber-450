/* First observation we should make to be able to solve this problem: if two matrices have common subsquare of size X, they also have common subsquares of sizes X-1, X-2, X-3,... ,1 (you may simply take part of large subsquare).

This observation should make idea of using binary search here quite obvious. Now we need to learn how to check that given matrices have common subsquare of size X.

Quite a few of tests are small&random enough to give you points even for some naive checking - running over all squares in first matrix, comparing them with all squares in second matrix (you may add some smart breaks here etc.). However, this isn't supposed to give you a full score.

First improvement is to learn how to compare two squares faster than with naive checking. Here hashing can help us.

Hashing will allow us to represent whole square as a single number, and compare two squares by comparing corresponding numbers.

Type "Rabin-Karp 2d" in Google and at the first page you'll have several different guides/implementations for 2d version of Rabin-Karp algorithm. If you are completely new to all these things - start with 1d version of algorithm (where we are comparing substrings instead of subsquares). After understanding 1d version - 2d version should be also pretty clear, because it is a simple generalization of 1d.

Now we have O(N^4) checker for particular value of X, which is still too slow (but much better than before). How to improve it even more? Instead of comparing our subsquare with every single subsquare from other matrix, we may compare it with all subsquares from that matrix at the same time. We are interested to know if there is a pair of equal subsquares; let's put all subsquares of first matrix in a set. Now for every subsquare from second matrix we can check if it has a pair in first matrix, by simply looking at our set. It gives us logN instead of N^2 here.

Now we have some sort of proper solution. Time limit isn't very strict; however, if you are actually going to use sets, it may be too slow. Instead you may store all values in sorted vector and use std::lower_bound() to check that some value is presented there. Also you may get rid of any % operations by doing all calculations modulo 2^64 (yes, there were no anti-hash tests in data set :) ) Such solution should get full score without any problems.  */
#include <bits/stdc++.h>

using namespace std;
 
long long s1[1<<10][1<<10],s2[1<<10][1<<10],
ar1[1<<10][1<<10],ar2[1<<10][1<<10],pw1[1<<22],pw2[1<<22],n2,m2;
long long l,r;
long long n1,m1;
 
long long get1(long a,long b,long c)
{	
	long long res=s1[a+c][b+c]-s1[a][b+c]-s1[a+c][b]+s1[a][b];
	res*=pw1[2000000-a]*pw2[2000000-b];
	return res;
}
long long get2(long a,long b,long c)
{
	long long res=s2[a+c][b+c]-s2[a][b+c]-s2[a+c][b]+s2[a][b];
	res*=pw1[2000000-a]*pw2[2000000-b];
	return res;
}
 
vector<long long> have;
 
bool solve(int X)
{
	have.clear();
	for (int i=0;i+X<=n1;i++)
	 for (int j=0;j+X<=m1;j++)
	  have.push_back(get1(i,j,X));
	
	sort(have.begin(),have.end());
	for (int i=0;i+X<=n2;i++)
	 for (int j=0;j+X<=m2;j++)
		{
			long long res=get2(i,j,X);
			int id=lower_bound(have.begin(),have.end(),res)-have.begin();
			if (id!=have.size()&&have[id]==res)
			 return true;
		}
	return false;
}
 
int main(){
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
pw1[0]=1;
for (int i=1;i<=2000000;i++)
	 pw1[i]=pw1[i-1]*173;
 
pw2[0]=1;
for (int i=1;i<=2000000;i++)
	pw2[i]=pw2[i-1]*137;
 
 
cin>>n1>>m1;
for (int i=1;i<=n1;i++)
 	for (int j=1;j<=m1;j++)
	  cin>>ar1[i][j];
 
cin>>n2>>m2;
for (int i=1;i<=n2;i++)
	for (int j=1;j<=m2;j++)
  		cin>>ar2[i][j];

for (int i=1;i<=n1;i++)
 	for (int j=1;j<=m1;j++)
  		s1[i][j]=s1[i][j-1]+s1[i-1][j]-s1[i-1][j-1]+ar1[i][j]*pw1[i]*pw2[j];
 
for (int i=1;i<=n2;i++)
 	for (int j=1;j<=m2;j++)
  		s2[i][j]=s2[i][j-1]+s2[i-1][j]-s2[i-1][j-1]+ar2[i][j]*pw1[i]*pw2[j];
 
l=0;
r=700;

while (l<r)
{
 	int mid=l+r+1;
 	mid/=2;
	if (solve(mid))l=mid;	
	 else
 	r=mid-1;
}

cout<<l<<endl;

return 0;}