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
    int n = 3;
    int m = 27;
    // find nth root of m using binary search

    // we can see that 1^3 , 2^3 , 3^3 , 4^3 ......
    // this is increasing and in sorted manner so we can apply binary search on it

    // search space - ans willbe between 1 to 27, so put low = 1 and high = 27

    //let us say find ans till 5 decimal places only 
    // so we will continue this process till   -      high-low>1e-6 (10 to power -6);
    
    int high = m;
    int low = 1;
    //time complexity = log(m);
    

}