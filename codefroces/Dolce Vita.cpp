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
        ll n,x;
        cin>>n>>x;
        ll arr[n];
    
        ll final=n;
        bool check=false;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            
        }
        sort(arr,arr+n);
        if(x<arr[0]){
            cout<<0<<endl;
            continue;
        }
        ll count=0;
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i];
            if(sum>x){
                break;
            }
            count++;
            ll diff=x-sum;
            count+=diff/(i+1);
        }
        cout<<count<<endl;
    }   
}