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
        ll n,m;
        cin>>n>>m;
        if(m<n){
            cout<<"NO"<<endl;
            continue;
        }
        if(n%2!=0){
            cout<<"YES"<<endl;
            for(int i=0;i<n-1;i++){
                cout<<1<<" ";
            }
            cout<<m-n+1<<endl;
            continue;
        }
        else{
            if(m%2!=0){
                cout<<"NO"<<endl;
                continue;
            }
            else{
                cout<<"YES"<<endl;
                for(int i=0;i<n-2;i++){
                    cout<<1<<" ";
                }
                cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<endl;
                continue;
            }
        }
    }
}