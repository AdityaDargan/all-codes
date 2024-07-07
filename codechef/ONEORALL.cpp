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
        ll n;
        cin>>n;
        ll arr[n];
        ll sm=0;
        ll mn=1e9+1;
        ll mx=0;

        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sm+=arr[i];
            if(arr[i]<mn){
                mn=arr[i];
            }
            if(arr[i]>mx){
                mx=arr[i];
            }
        }

        ll sm2=0;
        for(ll i=0;i<n;i++){
            sm2+=arr[i]-2;
        }

        if(sm%2==0){
            if(n%2==0){
                if(mn%2==1){
                    cout<<"CHEF"<<endl;
                    continue;
                }
                if(sm2%2==0){
                    cout<<"CHEFINA"<<endl;
                }  
                else{
                    cout<<"CHEF"<<endl;
                }
            }
            else{
                cout<<"CHEFINA"<<endl;
            }
        }
        else{
            if(n%2==0){
                if(mn%2==1){
                    cout<<"CHEF"<<endl;
                    continue;
                }
                if(sm2%2==0){
                    cout<<"CHEFINA"<<endl;
                }  
                else{
                    cout<<"CHEF"<<endl;
                }
            }
            else{
                cout<<"CHEF"<<endl;
            }
        }
    }
}