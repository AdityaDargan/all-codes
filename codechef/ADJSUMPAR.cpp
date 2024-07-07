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
        ll cnt=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(i<n-1){
                if(arr[i]%2!=0){
                    cnt++;
                }
            }
        }
        if(cnt%2==1 && arr[n-1]==1){
            cout<<"YES"<<endl;
        }
        else if(cnt%2==0 && arr[n-1]==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}