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
        ll n,m;
        cin>>n>>m;
        ll arr[n];
        map<ll,ll> left;
        map<ll,ll> came;
        map<ll,ll> stayed;
        for(int i=0;i<n+m+1;i++){
            left[i]=-1;
            came[i]=-1;
            stayed[i]=0;
        }
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            came[arr[i]]=0;
        }
        ll ans=0;
        ll prev=n;
        for(ll i=1;i<=m;i++){
            ll a,b;
            cin>>a>>b;
            a--;
            if(i==1){
                if(arr[a]==b){
                    ans+=n;
                    prev=n;
                }
                else{
                    left[arr[a]]=i;
                    came[b]=i;
                    stayed[arr[a]]=left[arr[a]]-came[arr[a]];
                    ans+=n+1;
                    prev=n+1;
                    arr[a]=b;
                }
                continue;
            }
            if(arr[a]==b){
                prev+=n;
                ans+=prev;
                continue;
            }
            left[arr[a]]=i;
            came[b]=i;
            stayed[arr[a]]+=left[arr[a]]-came[arr[a]];
            prev=prev+n+(i-stayed[b])-(i-stayed[arr[a]]);
            arr[a]=b;
            ans+=prev;

        }
        cout<<ans<<endl;
    }
}