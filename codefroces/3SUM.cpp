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
        map<ll,ll> m;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            m[arr[i]%10]++;
        }
        if(m[1]>=1 && m[2]>=1 && m[0]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[1]>=3){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[9]>=1 && m[4]>=1 && m[0]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[1]>=1 && m[3]>=1 && m[9]>=1){
            cout<<"YES"<<endl;
            continue;
        }

        if(m[9]>=1 && m[2]>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[8]>=1 && m[5]>=1 && m[0]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[1]>=1 && m[8]>=1 && m[4]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[3]>=1 && m[2]>=1 && m[8]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[7]>=1 && m[6]>=1 && m[0]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[1]>=1 && m[5]>=1 && m[7]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[7]>=1 && m[2]>=1 && m[4]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[7]>=1 && m[3]>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[1]>=1 && m[6]>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[5]>=1 && m[2]>=1 && m[6]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[6]>=1 && m[4]>=1 && m[3]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[3]>=1 && m[5]>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[5]>=1 && m[4]>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[8]>=2 && m[7]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[7]>=2 && m[9]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[3]>=1 && m[0]>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[9]>=2 && m[5]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m[9]>=1 && m[8]>=1 && m[6]>=1){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
        
    }
}