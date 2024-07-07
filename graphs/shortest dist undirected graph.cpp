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

vector<int> shortestPath(vector<vector<int>>& adj, int s){
    int N = adj.size();
    int dist[N];
    for(int i = 0;i<N;i++) dist[i] = 1e9;
    // BFS Implementation.
    dist[s] = 0; 
    queue<int> q;
    q.push(s); 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        for(auto it : adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = 1 + dist[node]; 
                q.push(it); 
            }
        }
    }
    
    vector<int> ans(N, -1);
    for(int i = 0;i<N;i++) {
        if(dist[i] != 1e9) {
            ans[i] = dist[i]; 
        }
    }
    return ans; 
}