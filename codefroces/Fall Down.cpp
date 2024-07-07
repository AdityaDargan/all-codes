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
        int n,m;
        cin>>n>>m;
        char arr[n][m];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        for(ll j=0;j<m;j++){
            ll base=n;
            for(ll i=n-1;i>=0;i--){
                if(arr[i][j]=='*'){
                    arr[i][j]='.';
                    arr[base-1][j]='*';
                    base--;
                }
                else if(arr[i][j]=='o'){
                    base=i;
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}