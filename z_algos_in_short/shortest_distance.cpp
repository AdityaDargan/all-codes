#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

// gives shortest path from start node to all other nodes O(nlogn) in weighted and directed graph

// could not detect -ve cycle - for that we have floyd warshall and bellman ford algos
vector<int> dijkstra(vector<vector<pair<int,int>>> &adj, int start){
    int n = adj.size();
    vector<int> dist(n,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();
        int d = top.first;
        int node = top.second;
        for(auto i:adj[node]){
            int nextNode = i.first;
            int w = i.second;
            if(d + w < dist[nextNode]){
                dist[nextNode] = d+w;
                pq.push({dist[nextNode],nextNode});
            }
        }
    }
    return dist;
}

//shortest path from one node to all others in undirected unweighted graph using bfs O(n)
vector<int> bfs(vector<vector<int>> &adj, int start){
    int n = adj.size();
    queue<int> q;
    vector<int> dist(n,INT_MAX);
    vector<int> vis(n,0);

    dist[start]=0;
    q.push(start);
    vis[start]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto i:adj[node]){
            if(!vis[i]){
                dist[i] = dist[node]+1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return dist;
}
