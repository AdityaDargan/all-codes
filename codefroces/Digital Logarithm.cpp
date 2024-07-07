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
        map<ll,ll> m1;
        map<ll,ll> m2;
        ll count=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>=10){
                arr[i]=log10(arr[i])+1;
                count++;
            }
            m1[arr[i]]++;
        }
        ll brr[n];
        for(ll i=0;i<n;i++){
            cin>>brr[i];
            if(brr[i]>=10){
                brr[i]=log10(brr[i])+1;
                count++;
            }
            m2[brr[i]]++;
        }
        cout<<count<<endl;
        for(auto i:m1){
            ll a=m1[i.first];
            ll b=m2[i.first];
            m1[i.first]-=min(a,b);
            m2[i.first]-=min(a,b);
            // m1[arr[i]]=min((ll)0,m1[arr[i]]-min(a,b));
            // m2[arr[i]]=min((ll)0,m2[arr[i]]-min(a,b));
            count+=m1[i.first];
            count+=m2[i.first];
            
        }
        cout<<count<<endl;
        // vector<ll> v;
        for(auto i:m2){
            ll a=m1[i.first];
            ll b=m2[i.first];
            // if(m1[brr[i]]==0){
            //     for(int i=0;i<m2[brr[i]];i++){
            //         v.push_back(brr[i]);
            //     }
            // }
            
            m1[i.first]-=min(a,b);
            m2[i.first]-=min(a,b);
            count+=m1[i.first];
            count+=m2[i.first];
        }
        //cout<<count<<endl;
        ll c=m1[1];
        ll d=m2[1];
        ll e=c+d;
        cout<<e<<endl;
        cout<<count-e<<endl;
    }
}