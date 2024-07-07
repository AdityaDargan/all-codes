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
        ll brr[n];
        for(ll i=0;i<n;i++){
            cin>>brr[i];
        }
        vector<ll> v1;
        vector<ll> v2;
        for(int i=0;i<n;i++){
            ll x=brr[i]-arr[i];
            if(x>=0){
                v1.push_back(brr[i]-arr[i]);
            }
            else{
                v2.push_back(x);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<ll>());
        ll ans=0;
        ll count=v1.size();
        ll i=0;
        ll j=0;
        if(v1.size()==0){
            cout<<0<<endl;
            continue;
        }
        if(v2.size()==0){
            cout<<v1.size()/2<<endl;
            continue;
        }

        while(i<v1.size() && j<v2.size()){
            ll temp=v1[i]+v2[j];
            if(temp>=0){
                i++;
                j++;
                ans++;
                count--;
            }
            else{
                i++;
            }
        }
        cout<<ans+(count/2)<<endl;
    }
}