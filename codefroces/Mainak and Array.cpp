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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> v;
        for(int i=0;i<n-1;i++){
            v.push_back(a[i]-a[i+1]);
        }
        v.push_back(a[n-1]-a[0]);
        for(int i=1;i<n;i++){
            v.push_back(a[i]-a[0]);
        }
        for(int i=0;i<n-1;i++){
            v.push_back(a[n-1]-a[i]);
        }
        cout<<*max_element(v.begin(),v.end())<<endl;
    }
}