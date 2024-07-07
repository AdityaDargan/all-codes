#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <stack>
#include <climits>
#include <unordered_map>
#define mod 1000000007
#define ll long long
using namespace std;

ll f[100001]; 
  
ll pow(ll a, ll b, ll MOD) 
{ 
 ll x=1,y=a;  
 while(b > 0) 
 	{ 
 		if(b%2 == 1) 
 	{ 
 		x=(x*y); 
 		if(x>MOD) x%=MOD; 
 	} 
 	y = (y*y); 
 	if(y>MOD) y%=MOD;  
 	b /= 2; 
 	} 
 return x; 
} 
ll InverseEuler(ll n, ll MOD) 
{ 
 return pow(n,MOD-2,MOD); 
} 
  
ll C(ll n, ll r, ll MOD) 
{ 
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD; 
} 
int main(){
    ll t;
    cin>>t;
    f[0] = 1; 
	for(int i = 1 ; i <= 100000 ; i++) 
		f[i] = (f[i-1]*i)%mod;
}