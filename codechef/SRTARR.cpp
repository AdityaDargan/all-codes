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
        ll count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && s[i+1]=='0'){
                count++;
            }
        }
        cout<<count<<endl;
    }
}