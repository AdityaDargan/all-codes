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


int n;
vector<int> fen;
void update(int i,int val){
    while(i<=n){
        fen[i]+=val;
        i = i + (i & (-i));
    }
    return;
}
int query(int ind){
    int ans = 0;
    while(ind>0){
        ans+=fen[ind];
        ind = ind - (ind & (-ind));
        // this removes the last set bit 
        // ind & (-ind) gives the last set bit 10100 -> 00100
    }
    return ans;
}


// everything is 1 indexed here
int main(){
    cin>>n;
    fen.resize(n+1,0);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        update(i,v[i]);
    }
    cout<<query(12)<<endl;
}