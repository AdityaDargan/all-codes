#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>bfs(vector<int> adj[],int n){
    
    vector<int> ans;
    int vis[n+1]={0};
    queue<int> q;
    q.push(1);
    ans.push_back(1);
    vis[1]=1;

    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto i:adj[top]){
            if(!vis[i]){
                q.push(i);
                ans.push_back(i);
                vis[i]=1;
            }
        }
    }
    return ans;
}
int main(){
    // bfs

    // level order traversal
    // we travel level 0 then 1 then 2 then 3
    // level = distance of that from starting node 

    // lets say starting node is 1 then nodes at dist 2 from it are level 2 nodes

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfs(adj,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
}