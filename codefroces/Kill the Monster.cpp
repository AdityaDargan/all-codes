#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#define ll unsigned long long int
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll hc,ac,hm,am;
        cin>>hc>>ac>>hm>>am;
        ll k,w,a;
        cin>>k>>w>>a;
        bool check=true;
        ll c;
        ll m;
        if(hc%am==0){
            c=hc/am;
        }
        else{
            c=hc/am+1;
        }
        if(hm%ac==0){
            m=hm/ac;
        }
        else{
            m=ceil((hm)/(ac))+1;
        }
        for(ll i=0;i<=k;i++){
            if(c>=m){
                check=false;
                break;
            }
            if((hc+i*a)%am==0){
                c=(hc+i*a)/am;
            }
            else{
                c=(hc+i*a)/am+1;
            }
            if(hm%(ac+(k-i)*w)==0){
                m=hm/(ac+(k-i)*w);
            }
            else{
                m=ceil((hm)/(ac+(k-i)*w))+1;
            }
        }

        if(c>=m){
            check=false;
        }
        if(!check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}