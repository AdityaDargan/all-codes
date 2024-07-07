#include <bits/stdc++.h>
#define ll long long
using namespace std;


/*
    let hashing number is p

    some important cases - 
    1. p > character set length ... bcz if p is less than it then collision would be too frequent
    
    2. start from a = 1, b = 2 bcz a=0 gives same value for a, aa, aaa.

    3. we do modulo mod, so the exponentially large powers doesn't overflow ll or long long -> getting mods would also result in collisions.

    4. for 26 chars -> use p = 31
    5. for 52 chars -> use p = 53

    6. the larger the mod, the lesser the collision will be

    7. common values - p = 31, m = 1e9+7
                 and - p = 37, m = 1e9+9
    
    8. probability of collision in case of 1 value -> 1/m = 10^-9
    9. when we hash with 2 different values so that probability changes to - 10^-18
    10. similar increase is there in 3 times hashing -> almost impossible collision

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
    return x;
}

vector<ll> prefix_hash1;
vector<ll> prefix_hash2;

vector<ll> mod_inverse1;
vector<ll> mod_inverse2;

ll hash1(string &s){
    ll n = s.length();

    ll p = 31;
    ll mod = 1e9+7;

    ll p_power = 1;
    ll hash = 0;

    prefix_hash1.push_back(0);

    for(ll i=0;i<n;i++){
        hash += ((s[i]-'a'+1)*p_power)%mod;
        hash%=mod;
        prefix_hash1.push_back(hash);
        mod_inverse1.push_back(mod_inverse(p_power,mod));
        p_power*=p;
        p_power%=mod;
    }
    return hash;
}

ll get_substring_hash1(ll i,ll j){
    // i and j should be in 0 indexing
    ll mod = 1e9 + 7;
    ll hash_val = 0;
    hash_val = prefix_hash1[j+1]-prefix_hash1[i];
    hash_val*=mod_inverse1[i];
    hash_val%=mod;
    return hash_val;
}

ll hash2(string &s){
    ll n = s.length();

    ll p = 31;
    ll mod = 1e9+7;

    ll p_power = 1;
    ll hash = 0;

    prefix_hash2.push_back(0);

    for(ll i=0;i<n;i++){
        hash += ((s[i]-'a'+1)*p_power)%mod;
        hash%=mod;
        prefix_hash2.push_back(hash);
        mod_inverse2.push_back(mod_inverse(p_power,mod));
        p_power*=p;
        p_power%=mod;
    }
    return hash;
}

// 3rd mod = 1e9+21

ll get_substring_hash2(ll i,ll j){
    // i and j should be in 0 indexing
    ll mod = 1e9 + 9;
    ll hash_val = 0;
    hash_val = prefix_hash2[j+1]-prefix_hash2[i];
    hash_val*=mod_inverse2[i];
    hash_val%=mod;
    return hash_val;
}


//###############   Actual Class - works fully   #########################3

long long power(long long x, long long y, long long p) {
    long long result = 1;
    for(; y; y >>= 1, x = x * x % p) {
        if(y & 1) {
            result = result * x % p;
        }
    }
    return result;
}
long long inverse(long long x, long long p) {
    return power(x, p - 2, p);
}


class Hash {
private:
    ll length;
    const ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    const ll p1 = 31, p2 = 37;
    vector<ll> hash1, hash2;
    pair<ll, ll> hash_pair;
 
public:
    inline static vector<ll> inv_pow1, inv_pow2;
    inline static ll inv_size = 1;
     
    Hash() {}
 
    Hash(const string& s) {
        length = s.size();
        hash1.resize(length);
        hash2.resize(length);
 
        ll h1 = 0, h2 = 0;
        long long p_pow1 = 1, p_pow2 = 1;
        for(ll i = 0; i < length; i++) {
            h1 = (h1 + (s[i] - 'a' + 1) * p_pow1) % mod1;
            h2 = (h2 + (s[i] - 'a' + 1) * p_pow2) % mod2;
            p_pow1 = (p_pow1 * p1) % mod1;
            p_pow2 = (p_pow2 * p2) % mod2;
            hash1[i] = h1;
            hash2[i] = h2;
        }
        hash_pair = make_pair(h1, h2);
 
        if(inv_size < length) {
            for(; inv_size < length; inv_size <<= 1);
             
            inv_pow1.resize(inv_size, -1);
            inv_pow2.resize(inv_size, -1);
 
            inv_pow1[inv_size - 1] = inverse(power(p1, inv_size - 1, mod1), mod1);
            inv_pow2[inv_size - 1] = inverse(power(p2, inv_size - 1, mod2), mod2);
             
            for(ll i = inv_size - 2; i >= 0 && inv_pow1[i] == -1; i--) {
                inv_pow1[i] = (1LL * inv_pow1[i + 1] * p1) % mod1;
                inv_pow2[i] = (1LL * inv_pow2[i + 1] * p2) % mod2;
            }
        }
    }
 
    ll size() {
        return length;
    }
 
    pair<ll, ll> prefix(const ll index) {
        return {hash1[index], hash2[index]};
    }
 
    pair<ll, ll> substr(const ll l, const ll r) {
        if(l == 0) {
            return {hash1[r], hash2[r]};
        }
        ll temp1 = hash1[r] - hash1[l - 1];
        ll temp2 = hash2[r] - hash2[l - 1];
        temp1 += (temp1 < 0 ? mod1 : 0);
        temp2 += (temp2 < 0 ? mod2 : 0);
        temp1 = (temp1 * 1LL * inv_pow1[l]) % mod1;
        temp2 = (temp2 * 1LL * inv_pow2[l]) % mod2;
        return {temp1, temp2};
    }
 
    bool operator==(const Hash& other) {
        return (hash_pair == other.hash_pair);
    }
};
