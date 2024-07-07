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
        ll sq=sqrt(n);
        ll count=0;
        for(int i=1;i<=sq;i++){
            if(n%i==0){
                count++;
            }
        }
        if(sq*sq==n){
            count+=count-2;
        }
        else{
            count+=count-1;
        }
        if(n%2==0){
            cout<<(count*2)-1<<endl;
        }
        else{
            cout<<count*2<<endl;
        }
    }
}