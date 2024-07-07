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
        int arr[2*n];
        for(ll i=0;i<2*n;i++){
            cin>>arr[i];
        }
        vector<vector<int>> v(2*n+1,vector<int>(2*n+1));
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                if(i!=j){
                    v[i][j]=arr[i]-arr[j];
                }
            }
        }
        map<int,int> m;
        map<int,int> mx;
        map<int,int> my;
        int x=0;
        int y=0;
        for(int i=0;i<2*n;i++){
            m.clear();
            m[v[x][y]]++;
            mx[x]++;
            my[y]++;
            x++;y++;
            bool check5 = false;
            for(int j=0;j<){
                
            }


        }
    }
}