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

vector <int> dijkstra(vector<vector<pair<int,int>>> adj, int s){
        int n = adj.size();
        // n = no. of nodes, s = source , gives shortest distance from source to each vertex in dist vector that is returned.
        // tc - O(ElogV)
        
        set<pair<int,int>> st;
        
        vector<int> dist(n,1e9);
        dist[s]=0;
        st.insert({0,s}); // {dist,node}
        
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            
            int distance = it.first;
            int node = it.second;
            
            for(auto i:adj[node]){
                int nextNode = i.first;
                int weight = i.second;
                if(distance + weight < dist[nextNode]){
                    
                    st.erase({dist[nextNode],nextNode});
                    dist[nextNode] = distance+weight;
                    
                    st.insert({dist[nextNode],nextNode});
                }
            }
        }
        return dist;
    }