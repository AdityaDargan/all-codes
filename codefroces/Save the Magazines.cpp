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
        string s;
        cin>>s;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ans=0;
        int index=-1;
        if(s[0]=='1'){
            ans+=arr[0];
        }
        else{
            index=0;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                if(index!=-1){
                    if(arr[index]>arr[i]){
                        ans+=arr[index];
                        s[i]='0';
                        index=i;
                    }
                    else{
                        ans+=arr[i];
                    }
                }
                else{
                    ans+=arr[i];
                }
            }
            else{
                index=i;
            }
        }
        cout<<ans<<endl;
    }
}