#include <iostream>
#include <stack> 
using namespace std;

int main(){
    stack<int> s;
    // push - inserting at top
    // pop - popping top element
    // top - gives top element
    s.push(2);
    s.push(4);
    s.push(3); 

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}