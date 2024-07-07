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
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        ll brr[q];
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<q;i++){
            cin>>brr[i];
            v.push_back(make_pair(brr[i],i));
        }
        sort(v.begin(),v.end());
        int ptr=0;
        ll ans=0;
        vector<pair<ll,ll>> v2;
        for(int i=0;i<q;i++){
            while(ptr<n){
                if(v[i].first>=arr[ptr]){
                    ans+=arr[ptr];
                    ptr++;
                }
                else{
                    break;
                }
            }
            v2.push_back(make_pair(v[i].second,ans));
        }
        sort(v2.begin(),v2.end());
        for(int i=0;i<v2.size();i++){
            cout<<v2[i].second<<" ";
        }
        cout<<endl;

    }
}