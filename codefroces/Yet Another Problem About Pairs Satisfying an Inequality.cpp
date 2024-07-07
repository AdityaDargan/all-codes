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
        bool b[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(i+1>arr[i]){
                b[i]=true;
            }
            else{
                b[i]=false;
            }
        }
        map<ll,ll> m;
        ll till=0;
        for(int i=0;i<n;i++){
            if(b[i]){
                till++;
            }
            m[i+1]=till;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(b[i]){
                ans+=m[arr[i]-1];
            }
        }
        cout<<ans<<endl;
    }
}