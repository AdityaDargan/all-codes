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
        ll arr[n*2];
        ll odd=0;
        ll even=0;
        for(ll i=0;i<2*n;i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(odd>=even){
            cout<<(odd-even)/2<<endl;
        }
        else{
            vector<ll> v;
            for(ll i=0;i<2*n;i++){
                ll count=0;
                if(arr[i]%2==0){
                    while(arr[i]%2==0){
                        count++;
                        arr[i]/=2;
                    }
                    v.push_back(count);
                }
            }
            sort(v.begin(),v.end());
            ll x=(even-odd)/2;
            ll ans=0;
            for(ll i=0;i<x;i++){

                ans+=v[i];
            }
            cout<<ans<<endl;
        }
    }
}