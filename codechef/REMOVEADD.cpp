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
        map<ll,ll> m;
        vector<ll> end;
        vector<ll> start;
        vector<ll> start1;
        vector<ll> end1;
        vector<ll> equal;
        map<ll,ll> m1;
        map<ll,ll> m2;
        for(ll i=0;i<n;i++){
            if(m[arr[i]]==0){
                m[arr[i]]=i+1;
            }
            else{
                if(m[arr[i]]<n-i){
                    start.push_back(m[arr[i]]);
                    m[arr[i]]=i+1;
                }
                else if(m[arr[i]]==n-i){
                    equal.push_back(m[arr[i]]);
                }
                else{
                    end.push_back(i+1);
                }
            }
        }
        for(ll i=0;i<n;i++){
            if(m1[arr[i]]==0){    
                m1[arr[i]]=i+1;
            }
            else{
                start1.push_back(m1[arr[i]]);
                m2[arr[i]]=i+1;
            }
        }
        for(ll i=0;i<n;i++){
            if(m2[arr[i]]==0){    
                m2[arr[i]]=i+1;
            }
            else{
                end1.push_back(m2[arr[i]]);
                m2[arr[i]]=i+1;
            }
        }
        if(start.size()>end.size()){
            for(int i=0;i<equal.size();i++){
                start.push_back(equal[i]);
            }
        }
        
        else{
            for(int i=0;i<equal.size();i++){
                end.push_back(equal[i]);
            }
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        // for(int i=0;i<start.size();i++){
        //     cout<<start[i];
        // }
        // cout<<endl;
        // for(int i=0;i<end.size();i++){
        //     cout<<end[i];
        // }
        vector<ll> ans;
        ans.push_back(2*(min(start.size(),end.size()))+max(start.size(),end.size()));
        if(start1.size()>0){
        ans.push_back(*max_element(start1.begin(),start1.end()));
        }   
        if(end1.size()>0){
        ans.push_back(*max_element(end1.begin(),end1.end()));
        }
        cout<<ans[0]<<ans[1]<<ans[2]<<endl;
        //cout<<*min_element(ans.begin(),ans.end())<<endl;
        
    }
}