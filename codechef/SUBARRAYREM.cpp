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
        int n;
        cin>>n;
        ll arr[n];
        int z=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                z++;
            }
        }

        if(n-z<z){
            cout<<n-z<<endl;
            continue;
        }
        int x=n-2*z;
        int y=x/3;
        cout<<z+y<<endl;
    }
}