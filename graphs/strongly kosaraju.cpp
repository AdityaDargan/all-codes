/*
strongly connected components 

do a dfs of the graph and when you return from a value put that in a stack so the one from which we return 1st, that is at the bottom.

kahin se bhi start ho dfs pr vo order of stack same rhega 

above is kind of topological sort
as in actual topo sort, cycle can't be there but in this cycle is present

ab scc1 -> scc2 -> scc3 -> scc4 

ab reverse all the edges in graph 

to scc 1 mei hum ghum skte ha lekin usse scc2 mei nhi ja payenge kbhi 

to top of stack pe scc 1 ka part hoga 

top ko nikalo run dfs mark visited sabko 

fir top se nikalte rho and if not vis to run its dfs.

jitni baar dfs call hoga utne components ha and har dfs call mei vo ek component ko dhundega 
*/

// implementation 
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

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj,stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT,vector<int> &temp) {
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adjT[node]) {
        if (!vis[it]) {
            dfs3(it, vis, adjT,temp);
        }
    }
}
vector<vector<int>> kosaraju(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 1; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    vector<vector<int>> adjT(n);
    for (int i = 1; i < n; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }
    vector<vector<int>> all_scc;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]){
            vector<int> temp;
            dfs3(node, vis, adjT, temp);
            all_scc.push_back(temp);
        }
    }
    return all_scc;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
    }
}