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
#define ll long long
using namespace std;


ll ncr(int n, int r)
{
    ll f = 1, k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            f *= n%(998244353);
            k *= r%(998244353);

            ll m = __gcd(f, k);

            f /= m;
            // f=f%(998244353);
            k /= m;
            // k=k%(998244353);
 
            n--;
            r--;
        }
    }
 
    else
        f = 1;
    return f%(998244353);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        if((n+m)%2==0){
            cout<<0<<endl;
        }
        else{
            ll num = ncr(n+m-2,n-1);
            ll temp = (n*m)-n-m+1;
            ll multi = powl(2,(temp));
            multi=multi%(998244353);
            ll bigc = ncr(n+m-1,((n+m-1)/2));
            ll ans = num*multi*bigc;
            ans=ans%(998244353);
            cout<<ans<<endl;
        }
    }
}