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
        ll n,a,b;
        cin>>n>>a>>b;
        ll ac=a;
        ll bc=b;
        vector<int> va;
        vector<int> vb;
        while(a){
            va.push_back(a%2);
            a/=2;
        }
        while(b){
            vb.push_back(b%2);
            b/=2;
        }
        if(va.size()==0){
            va.push_back(0);
        }
        if(vb.size()==0){
            vb.push_back(0);
        }
        int xa=n-va.size();
        int xb=n-vb.size();
        
        for(int i=0;i<xb;i++){
            vb.push_back(0);
        }
        for(int i=0;i<xa;i++){
            va.push_back(0);
        }

        reverse(va.begin(),va.end());
        reverse(vb.begin(),vb.end());

        // for(int i=0;i<va.size();i++){
        //     cout<<va[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<vb.size();i++){
        //     cout<<vb[i]<<" ";
        // }
        // cout<<endl;

        vector<ll> ans;
        vector<ll> ans2;
        ll f=1;
        for(int i=0;i<va.size();i++){
            if(va[i]==vb[i]){
                if(va[i]==0){
                    ans.push_back(1);
                    ans2.push_back(1);
                }
                else{
                    ans.push_back(0);
                    ans2.push_back(0);
                }
            }
            else{
                ans2.push_back(0);
                ans.push_back(f);
                if(f==0){
                    f=1;
                }
                else{
                    f=0;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        reverse(ans2.begin(),ans2.end());
        ll final=0;
        ll final2=0;
        ll j=1;
        for(int i=0;i<ans.size();i++){
            final+=j*ans[i];
            j*=2;
        }
        ll j2=1;
        for(int i=0;i<ans2.size();i++){
            final2+=j2*ans2[i];
            j2*=2;
        }
        if((final^ac)*(final^bc)>(final2^ac)*(final2^bc)){
            cout<<final<<endl;
        }
        else{
            cout<<final2<<endl;
        }
    }
}