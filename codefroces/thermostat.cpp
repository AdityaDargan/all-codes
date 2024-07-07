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
        ll l,r,x,a,b;
        cin>>l>>r>>x>>a>>b;
        ll diff = (b-a);
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(abs(diff)>=x){
            cout<<1<<endl;
            continue;
        }
        if(diff>0){
            if(a+diff+x<=r){
                cout<<2<<endl;
                continue;
            }
            else if(a-x>=l){
                cout<<2<<endl;
                continue;
            }
            else if(a+x<=r){
                if(a+diff-x>=l){
                    cout<<"3"<<endl;
                    continue;
                }
            }
        }
        else{
            diff=abs(diff);
            if(a-diff-x>=l){
                cout<<2<<endl;
                continue;
            }
            else if(a+x<=r){
                cout<<2<<endl;
                continue;
            }
            else if(a-x>=l){
                if(a-diff+x<=r){
                    cout<<"3"<<endl;
                    continue;
                }
            }
        }
        cout<<-1<<endl;
    }
}