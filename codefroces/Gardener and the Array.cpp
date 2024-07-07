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
        vector<vector<int>> v(n);
        bool ans=false;
        map<int,int> m;

        for(int i=0;i<n;i++){
            int len;
            cin>>len;
            bool check=false;
            while(len--){
                int temp;
                cin>>temp;
                v[i].push_back(temp);
                m[temp]++;
            }
        }

        for(int i=0;i<n;i++){
            bool check=false;
            for(int j=0;j<v[i].size();j++){
                if(m[v[i][j]]==1){
                    check=true;
                    break;
                }
            }
            if(!check){
                ans=true;
            }
        }

        if(ans){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}