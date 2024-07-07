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
        ll count=0;
        ll z=0;
        bool check=false;
        vector<int> v;
        sort(arr,arr+n);
        if(arr[0]>0){
            cout<<1<<endl;
            continue;
        }
        for(ll i=0;i<n;i++){
            if(arr[i]<=0){
                count++;
            }
            else{
                z=i;
                break;
            }
        }
        
        for(ll i=1;i<=z;i++){
            v.push_back(abs(arr[i]-arr[i-1]));
        }
        if(z!=0){
            for(ll i=0;i<v.size();i++){
                if(v[i]<arr[z]){
                    check=true;
                }
            }
            if(!check){
                cout<<count+1<<endl;
            }
            else{
                cout<<count<<endl;
            }
        }
        else{
            cout<<count<<endl;
        }
    }
}