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
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        ll brr[n];
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        for(ll i=0;i<n;i++){
            cin>>brr[i];
        }
        for(ll i=0;i<n;i++){
            v.push_back(make_pair(arr[i]+brr[i],arr[i]));
        }

        sort(v.begin(),v.end());


        ll ans=0;
        ll count=0;
        ll i=0;
        while(true){
            if(i>=n){
                break;
            }
            if(ans+v[i].first<=k){
                ans+=v[i].first;
                count++;
                i++;
            }
            else{
                break;
            }
        }
        // cout<<count<<endl;

        if(count==n){
            cout<<count<<endl;
            continue;
        }
        bool check=false;
        for(int j=0;j<n;j++){
            if(j<count){
                if(ans+v[i].first-v[j].first+v[j].second<=k){
                    check=true;
                    break;
                }
            }
            else{
                if(ans+v[j].second<=k){
                    check=true;
                    break;
                }
            }
        }
        if(check){
            cout<<count+1<<endl;
            continue;
        }
        cout<<count<<endl;
    }
}