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
        ll a,b;
        cin>>a>>b;
        bool check=false;

        while(a%b!=0){
            ll hcf = __gcd(a,b);
            if(hcf==1){
                check=true;
                break;
            }
            else if(b==hcf){
                break;
            }
            b=b/hcf;
        }
        if(check){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
}