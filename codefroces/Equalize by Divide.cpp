#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <climits>
#include <fstream>
#include <queue>
#include <stack>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n);
        bool check=false;
        bool check2=false;
        for(ll i=0;i<n;i++){
            cin>>v[i].first;
            v[i].second=i;
            if(v[i].first==1){
                check=true;
            }
            if(v[i].first!=1){
                check2=true;
            }
        }
        if(check && check2){
            cout<<-1<<endl;
            continue;
        }
        if(check && !check2){
            cout<<0<<endl;
            continue;
        }
        vector<pair<ll,ll>> ans;
        sort(v.begin(),v.end());
        ll mn=v[0].first;
        ll mi=v[0].second;
        ll i=n-1;
        
        while(true){
            if(i<0){
                break;
            }
            if(v[i].first>mn){
                if(v[i].first%mn==0){
                    v[i].first=v[i].first/mn;
                }
                else{
                    v[i].first=(v[i].first/mn)+1;
                }
                
                ans.push_back(make_pair(v[i].second,mi));
            }
            else{
                if(v[i].first<mn){
                    mn=v[i].first;
                    mi=v[i].second;
                    i=n-1;
                }
                else{
                    i--;
                }
            }
        }
        cout<<ans.size()<<endl;
        for(int j=0;j<ans.size();j++){
            cout<<ans[j].first+1<<" "<<ans[j].second+1<<endl;
        }
    }
}