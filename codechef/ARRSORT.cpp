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
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<ll> v;
        for(ll i=0;i<n;i++){
            v.push_back(abs(i+1-arr[i]));
        }
        ll hcf=__gcd(v[0],v[1]);
        for(int i=2;i<n;i++){
            hcf=__gcd(hcf,v[i]);
        }
        cout<<hcf<<endl;
    }
}