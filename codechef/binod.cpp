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
#define mod 1000000007
#define ll long long
using namespace std;

//use vectors for hashing, maps in c++ can fuck your brain with tle .
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        ll q;
        cin>>n>>q;
        vector<vector<ll>> arr2(n,vector<ll>(64,0));
        for(ll i=0;i<n;i++){
            ll temp;
            cin>>temp;
            ll f = 0;
            while (temp > 0) {
                arr2[i][f]=(temp%2);
                temp = temp / 2;
                f++;
            }
        }

        vector<vector<pair<ll,ll>>> ans(60);
        // map<ll,pair<ll,ll>> ans[60];
        for(ll i=0;i<60;i++){
            ll z=0;
            ll o=0;
            ans[i].push_back(make_pair(0,0));
            for(ll j=0;j<n;j++){
                ll x;
                if(arr2[j][i]==0){
                    z++;
                }
                else{
                    o++;
                }
                ans[i].push_back(make_pair(z,o));
            }
        }
        vector<ll> v;
        while(q--){
            ll k,l1,r1,l2,r2;
            cin>>k>>l1>>r1>>l2>>r2;
            ll z1,o1,z2,o2;
            z1 = ans[k][r1].first-ans[k][l1-1].first;
            z2 = ans[k][r2].first-ans[k][l2-1].first;
            o1 = ans[k][r1].second-ans[k][l1-1].second;
            o2 = ans[k][r2].second-ans[k][l2-1].second;

            v.push_back(z1*o2+z2*o1);
        }
        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
    }
}