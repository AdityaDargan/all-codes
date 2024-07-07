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
        sort(arr,arr+n);
        ll count=1;
        vector<pair<ll,ll>> v;
        for(ll i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                ++count;
            }
            else{
                v.push_back(make_pair(arr[i-1],count));
                count=1;
            }
            if(i==n-1){
                v.push_back(make_pair(arr[n-1],count));
            }
        }
        sort(v.begin(),v.end());
        ll num=1e9+7;
        ll ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i].second>1){
                ll multi=1%num;
                for(int j=0;j<v[i].second;j++){
                    multi=(multi*2)%num;
                }
                multi=(multi-v[i].second-1)%num;
                ans=(ans+multi)%num;
            }
        }
        cout<<ans<<endl;
    }
}