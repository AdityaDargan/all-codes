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
#include <climits>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<"?"<<" "<<1<<" "<<1<<endl;
        cout.flush();
        ll x;
        cin>>x;
        x++;

        cout<<"?"<<" "<<n<<" "<<m<<endl;
        cout.flush();
        ll z;
        cin>>z;
        ll r=n-z;
        ll c=m-z;

        if(c==x && r==x){
            cout<<"!"<<" "<<x<<" "<<x<<endl;
        }
        else if(c==x){
            cout<<"?"<<" "<<1<<" "<<c<<endl;
            cout.flush();
            ll y;
            cin>>y;
            cout<<"!"<<" "<<y+1<<" "<<c<<endl;
        }
        else if(r==x){
            cout<<"?"<<" "<<r<<" "<<1<<endl;
            cout.flush();
            ll y;
            cin>>y;
            cout<<"!"<<" "<<r<<" "<<y+1<<endl;
        }
        else{
            ll a=x,b=c;
            ll e=r,f=x;
            if(a>n || b<1){
                cout<<"!"<<" "<<e<<" "<<f<<endl;
            }
            else if(f>m || e<1){
                cout<<"!"<<" "<<a<<" "<<b<<endl;
            }
            else{
                cout<<"?"<<" "<<x<<" "<<1<<endl;
                cout.flush();
                ll y;
                cin>>y;
                if(y==x-1){
                    cout<<"!"<<" "<<r<<" "<<x<<endl; 
                }
                else{
                    cout<<"!"<<" "<<x<<" "<<c<<endl; 
                }
            }
                 
        }

    }
}