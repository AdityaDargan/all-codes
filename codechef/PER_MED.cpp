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
        for(int i=0;i<(n/2);i++){
            cout<<n-i<<" "<<i+1<<" ";
        }
        if(n%2!=0){
            cout<<(n/2)+1;
        }
        cout<<endl;
    }
}