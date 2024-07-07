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
        double n;
        cin>>n;
        double x=n-3;
        double y=ceil(x/double(3));
        if(n-y-y-1-2==0){
            cout<<y<<" "<<y+2<<" "<<1<<endl;
            continue;
        }
        cout<<y+1<<" "<<y+2<<" "<<n-y-1-y-2<<endl;

    }
}