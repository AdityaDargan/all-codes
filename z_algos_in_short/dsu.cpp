#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class dsu{
    public:
    vector<int> size,par;
    dsu(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }
    int find(int k){
        if(par[k]==k)return k;
        return par[k] = find(par[k]);
    }
    bool merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b)return false;
        if(size[a]>size[b]){
            size[a]+=size[b];
            par[b] = a;
        }
        else{
            size[b]+=size[a];
            par[a] = b;
        }
        return true;
    }
};