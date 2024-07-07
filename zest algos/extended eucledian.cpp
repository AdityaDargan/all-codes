#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;


// ax+by = c;
// its solution exists only if gcd(a,b) divides c;
// or solution exists when c is a multiple of gcd(a,b);


// extended eucledian algorithm
// as acc to above we say that ax + by = gcd(a,b)

// let a>b => gcd(a,b) = gcd(b,a%b)
// ax + by = gcd(a,b)
// now to find x and y

// MATHS for the same - 
/*
    1 - ax + by = gcd(a,b)
    2 - gcd(b%a,a) = gcd(a,b);
    3 - gcd(b%a,a) = (b%a)x1 + ay1 (using 1 and 2)
    4 - b%a = b - a*(b/a) (general)

    5 - gcd(a,b) = ax+by = ay1 + [b-a*(b/a)]x1 (using 3 and 4)
    6 - gcd(a,b) ==== ay1 + bx1 -a*(b/a)x1 ====== a(y1 - (b/a)x1) + bx1 (simplified)


    7 - a(y1 - (b/a)x1) + bx1 === ax + by
    

    using 7
    8) y = x1
    9) x = (y1 - (b/a)x1)
*/

int gcd(int a,int b,int *x,int *y){
    if(a==0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1,y1;

    int ans = gcd(b%a,a,&x1,&y1);

    *y = x1;
    *x = (y1 - (b/a)*x1);
    return ans;
}

int gcd_extended(int a,int b){
    int x,y;
    int ans = gcd(a,b,&x,&y);

    return ans;
    
    // we will find gcd(a,b) and also values of x and y where -
    // ax + by = gcd(a,b)

    // cout<<"Gcd = "<<ans<<endl;
    // cout<<"x = "<<x<<endl;
    // cout<<"y = "<<y<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int ans = gcd_extended(a,b);
        cout<<ans<<endl;
    }
}