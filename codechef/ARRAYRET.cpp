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
        ll min=1e9+7;
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]<min){
                min=arr[i];
            }
        }
        sum=sum/(n+1);
        --min;
        for(int i=0;i<n;i++){
            cout<<arr[i]-sum<<" ";
        }
        cout<<endl;

    }
}