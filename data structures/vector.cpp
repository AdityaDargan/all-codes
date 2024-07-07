#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v={1,3,5,1,2,2,1,6,4,7,3,2,5,4,3};
    cout<<v[0];
    v.erase(v.begin()+0);
    cout<<v[0]<<endl;
    v.insert(v.begin()+1,10);
    cout<<v[0]<<" "<<v[1]<<" "<<v[2];

    
}