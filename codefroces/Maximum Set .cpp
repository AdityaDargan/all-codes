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
#define mod 998244353
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;

        ll x=r/l;
        x=log2(x)+1;
        cout<<x<<" ";
        ll y=powl(2,x-1);
        ll z=y*3;
        z=z/2;

        ll ans=0;

        ll a=r/y;
        ans+=a-l+1;
        ans%=mod;
        ll b=r/z;
        if(b>=l){
            ans+=((x-1)%mod)*((b-l+1)%mod);
        }
        ans%=mod;

        cout<<ans<<endl;
    }
}