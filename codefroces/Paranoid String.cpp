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
        string s;
        cin>>s;
        ll count=n;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                count+=i;
            }
        }
        cout<<count<<endl;
    }
}