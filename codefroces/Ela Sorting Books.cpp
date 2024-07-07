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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int> m;
        string ans="";
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        int x=n/k;
        for(int j=0;j<k;j++){
            bool check=true;
            for(int i=0;i<x;i++){
                if(m['a'+i]<=0){
                    check=false;
                    ans+='a'+i;
                    break;
                }
                m['a'+i]--;
            }
            if(check){
                ans+='a'+x;
            }
        }
        cout<<ans<<endl;
    }
}