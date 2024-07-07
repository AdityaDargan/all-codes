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
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        vector<ll> v;
        for(ll i=0;i<n-2;i++){
            for(ll j=i+2;j<n;j++){
                ll x=((arr[i]+arr[j])/2);
                ll low=lower_bound(arr+i+1,arr+j,x)-arr;
                ll y=1e9+1;
                ll z=1e9+1;
                if(arr[low]!=x){
                    low--;
                }
                ll high=low+1;

                if(low<j && low>i){
                    y = abs(3*arr[low]-(arr[i]+arr[j]+arr[low]));
                }
                if(high<j && high>i){
                    z = abs(3*arr[high]-(arr[i]+arr[j]+arr[high]));
                }
                if(y<z){
                    v.push_back(y);
                }
                else{
                    v.push_back(z);
                }
            }
        }
        cout<<*min_element(v.begin(),v.end())<<endl;
    }
}