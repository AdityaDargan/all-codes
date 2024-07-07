#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    // push - insert at end;
    // pop - insert first element 
    // front - shows front element 
    q.push(3);
    q.push(4);
    q.push(2);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}