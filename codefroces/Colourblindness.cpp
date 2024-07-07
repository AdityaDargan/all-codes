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
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        bool check=true;
        for(int i=0;i<n;i++){
            if((s1[i]=='R' && s2[i]!='R')||(s2[i]=='R' && s1[i]!='R')){
                check=false;
            }
        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}