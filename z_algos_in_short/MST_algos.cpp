#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// minimum spanning tree algos
// applied on connected, weighted, undirected graphs


// kruskal algorithm
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

// returns a vector with 3 values - w,u,v depicting an edge
// input takes an adj list
// starts by adding minimum edges as sorted list and then builds the tree by adding those edges only which are not yet connected

vector<vector<int>> kruskal(vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    vector<vector<int>> list;
    // convert adj to list of edges - 1 based
    for(int u=1;u<=n;u++){
        for(auto p:adj[u]){
            int v = p.first;
            int w = p.second;
            if(u<v){
                list.push_back({w,u,v});
            }
        }
    }
    sort(list.begin(),list.end());
    dsu dsu(n);
    vector<vector<int>> ans;

    for(auto &i: list){
        int w = i[0], u = i[1], v = i[2];
        if(dsu.merge(u,v)){
            ans.push_back({w,u,v});
        }
    }
    return ans;
}

// prims algorithm - same input and outputs
// start with any node - put all its edges in a priority queue, and then take the smallest one and connect it if it has already not been visited 

vector<vector<int>> prim(vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    // 1 based indexing
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    vector<vector<int>> ans;
    vector<int> vis(n,0);
    vis[1] = 1;
    for(auto i:adj[1]){
        pq.push({i.second,1,i.first});
    }
    while(!pq.empty()){
        vector<int> p = pq.top();
        pq.pop();
        int w = p[0], u = p[1], v = p[2];
        if(!vis[v]){
            vis[v] = 1;
            ans.push_back(p);
            for(auto i:adj[v]){
                pq.push({i.second,v,i.first});
            }
        }
    }
    return ans;
}