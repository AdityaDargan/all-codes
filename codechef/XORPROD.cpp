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
#define mod 998244353
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr;
        ll one=0;
        for(ll i=0;i<n;i++){
            ll temp;
            cin>>temp;
            if(temp!=1){
                arr.push_back(temp);
            }
            else{
                one++;
            }
        }
        ll prod=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0 && one>0){
                one--;
                arr[i]=arr[i]+1;
            }
        }
        for(int i=0;i<arr.size();i++){
            prod*=arr[i]%mod;
            prod%=mod;
        }
        prod%=mod;
        cout<<prod<<endl;
    }
}