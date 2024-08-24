#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ancestor;
void binary_lifting(vector<vector<int>> &adj, int node, int par){
    int n = adj.size();
    for(int i=0;i<20;i++){
        if(i==0){
            ancestor[i][node]=par;
            continue;
        }
        int prev_k_ancestor = ancestor[i-1][node];
        if(prev_k_ancestor==-1){
            ancestor[i][node]=-1;
            continue;
        }
        ancestor[i][node] = ancestor[i-1][prev_k_ancestor];
    }
    for(auto i:adj[node]){
        if(i==par)continue;
        binary_lifting(adj,i,node);
    }
    return;
}

int getKthAncestor(int node, int k) {
    if(k==0){
        return node;
    }
    vector<int> bin;
    while(k){
        bin.push_back(k%2);
        k/=2;
    }
    int cur = node;
    for(int i=0;i<bin.size();i++){
        if(bin[i]==1) cur = ancestor[i][cur];
        if(cur==-1)break;
    }
    return cur;
}

int lca(){
    // store height of all -> now to compare h1 and h2
    // we need to get lca of 2 nodes which are at h1 and h2
    // 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m = n-1;
        // cin>>m;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ancestor.clear();
        ancestor.resize(20,vector<int>(n+1));
        int root = 1;
        binary_lifting(adj,root,-1);
        // assuming root is 1 so its par = -1
    }
}