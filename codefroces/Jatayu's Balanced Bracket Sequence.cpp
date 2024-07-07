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
        vector<ll> q;
        ll count=0;
        ll count2=0;
        map<ll,ll> m;
        vector<ll> v;
        for(int i=0;i<2*n;i++){
            if(q.size()==0 && i>0){
                count=1;        
            }
            if(s[i]=='('){
                q.push_back(1);
            }
            else{
                if(m[q.size()]==0){
                    v.push_back(q.size());
                    m[q.size()]++;
                }
                q.pop_back();
                
            }
        }
        cout<<v.size()+count<<endl;
    }
}