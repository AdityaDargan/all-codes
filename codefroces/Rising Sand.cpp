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
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll count=0;
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i+1]+a[i-1]){
                count++;
            }
        }
        if(k==1){
            if(n%2==0){
                cout<<(n/2)-1<<endl;
            }
            else{
                cout<<n/2<<endl;
            }
        }
        else{
            cout<<count<<endl;
        }
    }
}