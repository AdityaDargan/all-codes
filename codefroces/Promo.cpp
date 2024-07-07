#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#define ll long long
using namespace std;

int main(){
    ll n,q;
    cin>>n>>q;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    map<ll,ll> m;
    ll sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=arr[i];
        m[n-i]=sum;
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=m[x]-m[x-y];
        cout<<ans<<endl;
    }
}