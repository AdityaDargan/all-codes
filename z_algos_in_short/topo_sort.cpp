#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

// in directed acyclic graphs only
// sort graph nodes in such a way that if a path exists from a to b then a comes before b in the sorted order

void dfs(int node,vector<int> &v,vector<vector<int>> &adj,vector<int> &vis){
    if(vis[node])return;
    vis[node] = 1;
    for(auto i:adj[node]){
        dfs(i,v,adj,vis);
    }
    v.push_back(node);
    return;
}
// 1 based indexing
vector<int> topo_dfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> v;
    vector<int> vis(n,0);
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,v,adj,vis);
    }
    reverse(v.begin(),v.end());
    return v;
}


// 1 based indexing
vector<int> topo_bfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> indegree(n,0);
    queue<int> q;

    for(int i=1;i<=n;i++){
        for(auto node:adj[i])indegree[node]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }   
    return ans;
}
