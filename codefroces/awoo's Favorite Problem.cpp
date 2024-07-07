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
        string f;
        cin>>s>>f;
        map<char,ll> m;
        map<char,ll> m2;
        ll a1=0,a2=0,b1=0,b2=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a1++;
            }
            else if(s[i]=='b'){
                b1++;
            }
            else if(s[i]=='c'){
                c1++;
            }
            if(f[i]=='a'){
                a2++;
            }
            else if(f[i]=='b'){
                b2++;
            }
            else if(f[i]=='c'){
                c2++;
            }
        }
        if(a1!=a2 || b1!=b2 || c1!=c2){
            cout<<"NO"<<endl;
            continue;
        }
        ll mx='a';
        bool check=true;
        for(ll i=0;i<n;i++){
            if(s[i]!=f[i]){
                if(s[i]<mx){
                    check=false;
                    break;
                }
                else{
                    mx=s[i];
                }
                m[s[i]]++;
                m2[f[i]]++;
                if(m['a']==m2['a'] && m['b']==m2['b'] && m['c']==m2['c']){
                    if(m['a']>m['b'] || m['c']>m['b']){
                        check=false;
                        break;
                    }
                    m['a']=0;
                    m['b']=0;
                    m['c']=0;
                    m2['a']=0;
                    m2['b']=0;
                    m2['c']=0;
                    mx='a';
                }
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