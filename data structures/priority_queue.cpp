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

int main(){
    priority_queue<int> pq; //max heap is default 
    pq.push(3);
    pq.push(4);
    // sort in decreasing order
    cout<<pq.top();

    priority_queue<int,vector<int>,greater<int>> p;
    p.push(3);
    p.push(2);
    cout<<endl<<p.top();// min heap - sorted ascending order


}