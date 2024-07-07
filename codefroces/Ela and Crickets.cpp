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
        int a[3];
        int b[3];
        int r;
        int c;
        int n;
        cin>>n;
        cin>>a[0]>>b[0]>>a[1]>>b[1]>>a[2]>>b[2];
        sort(a,a+3);
        sort(b,b+3);
        r=a[1];
        c=b[1];
        int x,y;
        cin>>x>>y;
        if((r==1 || r==n) && (c==1 || c==n)){
            if(x==r || y==c){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            if(abs((x-r))%2==0 || (abs(y-c))%2==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}