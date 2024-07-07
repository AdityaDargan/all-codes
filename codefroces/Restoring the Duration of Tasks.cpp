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
        ll s[n];
        for(ll i=0;i<n;i++){
            cin>>s[i];
        }
        ll f[n];
        for(ll i=0;i<n;i++){
            cin>>f[i];
        }
        cout<<f[0]-s[0]<<" ";
        for(ll i=1;i<n;i++){
            cout<<min((f[i]-s[i]),(f[i]-f[i-1]))<<" ";
        }
        cout<<endl;
    }
}