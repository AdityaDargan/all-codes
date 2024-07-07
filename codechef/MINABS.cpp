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
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(s2[i]>s1[i]){
                v.push_back(make_pair(s2[i]-s1[i],-26+s2[i]-s1[i]));
            }
            else{
                v.push_back(make_pair(26-s1[i]+s2[i],-s1[i]+s2[i]));
            }
            // cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        int score =0 ;
        for(int i=0;i<n;i++){
            if(abs(score+v[i].first)<abs(score+v[i].second)){
                score+=v[i].first;
            }
            else{
                score+=v[i].second;
            }
        }
        cout<<abs(score)<<endl;
    }
}