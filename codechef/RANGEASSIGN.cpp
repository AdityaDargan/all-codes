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
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        } 
        if(n<=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(arr[0]==arr[n-1]){
            cout<<"YES"<<endl;
            continue;
        }
        bool check=true;
        for(int i=1;i<n-1;i++){
            if(arr[i]==arr[0] && arr[i+1]==arr[n-1]){
                check=false;
                break;
            }
        }
        for(int i=n-2;i>=1;i--){
            if(arr[i]==arr[n-1] && arr[i-1]==arr[0]){
                check=false;
                break;
            }
        }
        if(check){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}