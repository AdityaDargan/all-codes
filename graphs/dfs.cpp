#include <iostream>
#include <vector>
using namespace std;

vector<int> list;

void dfs(vector<int> adj[],int node, int vis[]){
    if(!vis[node]){
        vis[node]=1;
        list.push_back(node);
        for(auto it:adj[node]){
            dfs(adj,it,vis);
        }
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[n+1]={0};
    dfs(adj,1,vis);
    for(int i=0;i<n;i++){
        cout<<list[i]<<" ";
    }
}