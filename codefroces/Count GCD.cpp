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
#define mod 998244353
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        bool check=true;
        for(ll i=0;i<n-1;i++){
            if(arr[i]<arr[i+1] || arr[i]%arr[i+1]!=0){
                check=false;
                break;
            }
        }
        if(!check){
            cout<<0<<endl;
            continue;
        }
        vector<ll> ans;
        ans.push_back(1);
        for(ll i=1;i<n;i++){
            ll a = m/arr[i];
            ll b = m/arr[i-1];
            ans.push_back(max(a-b,1LL));
        }
        ll x=1;
        for(ll i=0;i<n;i++){
            x=((x%mod)*(ans[i]%mod))%mod;
        }
        ll p = x%mod;
        cout<<p<<endl;
    }
}