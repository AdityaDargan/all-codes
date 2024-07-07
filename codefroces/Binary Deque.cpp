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
        ll s;
        cin>>n>>s;
        ll arr[n];
        ll sum=0;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]==1){
                v.push_back(i+1);
            }
        }
        if(sum<s){
            cout<<-1<<endl;
            continue;
        }
        if(sum==s){
            cout<<0<<endl;
            continue;
        }
        ll num=sum-s;
        vector<ll> v2;
        v2.push_back(v[0]-1);
        for(int i=1;i<v.size();i++){
            v2.push_back(v[i]-v[i-1]-1);
        }
        v2.push_back(n-v[v.size()-1]);
        map<ll,ll> m1;
        map<ll,ll> m2;
        ll sum1=0;
        ll sum2=0;
        for(int i=0;i<v2.size()-1;i++){
            sum1+=v2[i]+1;
            sum2+=v2[v2.size()-i-1]+1;
            m1[i+1]=sum1;
            m2[i+1]=sum2;
        }
        vector<ll> ans;
        for(int i=0;i<=num;i++){
            if(m1[i]>0 || m2[num-i]>0){
                ans.push_back(m1[i]+m2[num-i]);
            }
        }
        cout<<*min_element(ans.begin(),ans.end())<<endl;
    }
}