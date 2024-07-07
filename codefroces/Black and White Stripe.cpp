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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll white=0;
        vector<ll> v;
        for(int i=0;i<k;i++){
            if(s[i]=='W'){
                white++;
            }
        }
        v.push_back(white);
        for(int i=k;i<n;i++){
            if(s[i]=='W'){
                white++;
            }
            if(s[i-k]=='W'){
                white--;
            }
            v.push_back(white);
        }
        cout<<*min_element(v.begin(),v.end())<<endl;
    }
}