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
        int n;
        cin>>n;
        string s1;
        cin>>s1;
        string s2;
        cin>>s2;
        map<char,int> m;
        for(int i=0;i<n;i++){
            m[s1[i]]++;
        }
        map<char,int> m2;
        vector<int> v;
        for(int i=0;i<n;i++){
            m2[s2[i]]++;
        }
        for(auto i:m){
            v.push_back(min(i.second,m2[i.first]));
        }
        cout<<*max_element(v.begin(),v.end())<<endl;
    }
}