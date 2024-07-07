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

void dfs(int node, vector<int> &vis, stack<int> &st,vector<vector<int>> adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort(int n, vector<vector<int>> adj)
{
    vector<int> vis(n,0);

    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        
    }
}