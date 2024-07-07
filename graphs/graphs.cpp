#include <iostream> 
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    // n =nodes , m=edges

    // in matrix way mark a[u][v]=1 && a[v][u]=1
    // and rest 0, but that costs n^2 space 
    // bcz of n*n matrix 

    // adjacency list - 
    vector<int> adj[n+1];
    // used  n+1 for 1 based indexing , of graph values


    // weighted graph - 
    vector<pair<int,int>> adjwt[n+1];


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //if directed edge 1->2 then adj[1].push(2)
        // if undirect edge between 3 and 4
        // then adj[3].push(4) , adj[4].push(3) 


        // undirected edge space = 2*m bcz m edges and that connect to 2 nodes each

        // directed edge space = m bcz m edges only

        // assumes undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
        // this was unwighted graph 


        // weighted graph 

        // in adjacency matrix we store a[u][v]=wt and    a[v][u]=wt but takes too much space

        // adjacency list -> input wt

        // store pairs in vector in array
        // 1 ---4---> 2 , here 4 is wt
        // then store as adj[u].push_back({2,4})
        // pair.first = target vertex, pair.second = wt
        int wt;
        cin>>wt;

        adjwt[u].push_back({v,wt});
        adjwt[v].push_back({u,wt});

    }
}