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
        ll arr[n];
        vector<ll> v;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>=i+1){
                v.push_back(0);
            }
            else{
                v.push_back(arr[i]-i-1);
            }
        }
        ll count=0;
        ll start=0;
        ll end=0;
        ll num=0;
        ll ans=n;
        ll prev=0;
        bool check=true;
        while(end!=n){
            if(num+v[end]<0){
                count=end-start;
                start=abs(v[end]);
                num=start;
                check=false;
                ans+=((count)*(count-1))/2;
                ans-=prev;
                count=end-start;
                prev=((count)*(count-1))/2;
            }
            else{
                check=true;
                end++;
            }

        }
        if(check){
            count=end-start;
        }
        else{
            count=0;
        }
        ans+=((count)*(count-1))/2;
        ans-=prev;
        cout<<ans<<endl;
    }
}