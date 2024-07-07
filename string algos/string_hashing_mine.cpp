#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX_INT = 300005;
ll mod_inverse1[MAX_INT];
ll mod_inverse2[MAX_INT];
ll prefix_hash1[MAX_INT];
ll prefix_hash2[MAX_INT];

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
    return x;
}

class hash


int main(){
    ll p1 = 31;
    ll p2 = 37;
    ll m1 = 1e9+7;
    ll m2 = 1e9+9;
    ll pow_p1 = 1;
    ll pow_p2 = 1;
    for(ll i=0;i<MAX_INT;i++){
        mod_inverse1[i] = mod_inverse(pow_p1,m1);
        mod_inverse2[i] = mod_inverse(pow_p2,m2);
        pow_p1*=p1;
        pow_p2*=p2;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

    }
}