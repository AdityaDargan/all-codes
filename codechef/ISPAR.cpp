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
        ll ans=0;
        ll n,k;
        cin>>n>>k;
        if(k==1){
            ans=n;
        }
        else if(k==2){
            ans=1;
        }
        else{
            if(k%2==0){
                ans=2;
            }
            else{
                ans=k-1;
            }
        }
        if(ans%2==0){
            cout<<"EVEN"<<endl;
        }
        else{
            cout<<"ODD"<<endl;
        }
    }
}