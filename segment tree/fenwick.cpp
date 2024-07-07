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
    while(i<n){
        fen[i]+=val;
        i = i + (i & (-i));
    }
    return;
}
int sum(int ind){
    int ans = 0;
    while(ind!=0){
        ans+=fen[ind];
        ind = ind - (ind & (-ind));
    }
    return ans;
}

int main(){
    cin>>n;
    fen.resize(n,0);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        update(i,v[i]);
    }
    cout<<sum(12)<<endl;
    cout<<sum(14)<<endl;
}