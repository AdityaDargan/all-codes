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
        sort(arr,arr+n);
        bool check=false;
        if(n==4){
            if(arr[n-1]+arr[0]==0){
                if(arr[1]+arr[2]==0){
                    check=true;
                }
            }
            
        }
        if(n==3){
            int s=accumulate(arr,arr+n,0);
            if(s==arr[0] || s==arr[1] || s==arr[2]){
                check=true;
            }
        }
        
        else{
            if(arr[n-1]+arr[0]==0){
                bool a=true;
                for(int i=1;i<n-1;i++){
                    if(arr[i]!=0){
                        a=false;
                    }
                }
                if(a){
                    check=true;
                }
            }
            bool a=true;
            ll count=0;
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    count++;
                }
            }
            if(count==n-1 || count==n){
                check=true;
            }

        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}