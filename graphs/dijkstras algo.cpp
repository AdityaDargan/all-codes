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
#include <set>
#define mod 1000000007
#define ll long long
using namespace std;

vector <ll> dijkstra(vector<vector<pair<ll,ll>>> adj, ll s){
    ll n = adj.size();
    // n = no. of nodes, s = source , gives shortest distance from source to each vertex in dist vector that is returned.
    // tc - O(ElogV)
    
    set<pair<ll,ll>> st;
    
    vector<ll> dist(n,1e18);
    dist[s]=0;
    st.insert({0,s}); // {dist,node}
    
    while(!st.empty()){
        auto it = *(st.begin());
        
        ll distance = it.first;
        ll node = it.second;

        st.erase(it);
        
        for(auto i:adj[node]){
            ll nextNode = i.first;
            ll weight = i.second;
            if(distance + weight < dist[nextNode]){
                
                st.erase({dist[nextNode],nextNode});
                dist[nextNode] = distance+weight;
                
                st.insert({dist[nextNode],nextNode});
            }
        }
    }
    return dist;
}