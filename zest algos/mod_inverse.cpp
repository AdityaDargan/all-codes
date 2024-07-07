#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;


// (a*b) mod m = 1
// a is given to us, m is given to us 
// condition - a and m should be co primefor b to exist => gcd(a,m) = 1
// b is our modulo multiplicative inverse 

// to find b we will use extended eucledian theorem 

// maths - 
/*
    we know that ax+by = gcd(a,b)
    and also ab%m = 1%m
    => (ab-1)%m = 0
    => ab - 1 = mq // q is any constant -1

    as gcd(a,m) = 1;
    => ax + my = 1
    => ax -1 = my // y is a constant -2
    => comparing eqn 1 with eqn 2. we get,
    b = x
    => in our euclid extended algo we have to put -> a = a, b = m and the x we get would be our modulo multiplicative inverse.
*/

ll gcd(ll a,ll b,ll *x,ll *y){
    if(a==0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1,y1;

    ll ans = gcd(b%a,a,&x1,&y1);

    *y = x1;
    *x = (y1 - (b/a)*x1);
    return ans;
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    ll g = gcd(a,m,&x,&y);
    if(g!=1){
        cout<<"Modulo mulitplicative inverse doesn't exist"<<endl;
        return -1;
    }
    cout<<"modulo multiplicative inverse(b) is = "<<x<<endl;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a,m;
        cin>>a>>m;
        ll ans = mod_inverse(a,m);
        cout<<ans<<endl;
    }
}