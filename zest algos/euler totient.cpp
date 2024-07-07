#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class segTree{
    public:
    vector<ll> seg;
    segTree(ll n){
        seg.resize(4*n+1);
    }

    void build(ll ind, ll low, ll high, vector<ll> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        return;
    }

    void update(ll ind,ll low,ll high,ll index,ll val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        ll mid = (low+high)/2;

        if(index<=mid){update(2*ind+1,low,mid,index,val);}
        
        else{update(2*ind+2,mid+1,high,index,val);}

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        return;
    }
    ll query(ll ind,ll low,ll high,ll l,ll r){
        // No Overlap
        if(l>high || r<low){
            return 0;
        }
        // Full Overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        // Partial Overlap
        ll mid=(low+high)/2;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(m);

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        for(ll i=0;i<m;i++){
            ll x;
            cin>>x;
            c[i]=x;
        }

        ll ans = 0;

        sort(c.begin(),c.end());
        reverse(c.begin(),c.end());
        vector<pair<ll,ll>> v;

        map<ll,ll> mp;
        for(ll i=0;i<n;i++){
            ll cost = a[i];
            ll loss = a[i]-b[i];
            if(mp[cost]==0){
                mp[cost] = loss;
            }
            else{
                mp[cost] = min(mp[cost],loss);
            }
        }

        map<ll,ll> mp2;
        for(auto i:mp){
            ll loss = i.second;
            ll cost = i.first;
            if(mp2[loss]==0){
                mp2[loss]=cost;
            }
            else{
                mp2[loss] = min(mp2[loss],cost);
            }
        }

        for(auto i:mp2){
            ll loss = i.first;
            ll cost = i.second;
            v.push_back({cost,loss});
        }
        sort(v.begin(),v.end());


        ll p = v.size();

        ll ans = 0;
        vector<ll> arr;
        vector<ll> arr_cost;
        for(ll i=0;i<p;i++){
            arr.push_back(v[i].second);
            arr_cost.push_back(v[i].first);
        }

        segTree st(p);
        st.build(0,0,p-1,arr);
        map<ll,ll> mp3;

        for(ll i=0;i<p;i++){
            mp3[arr[i]] = i;
        }
        
        for(auto num:c){
            while(c>0){
                ll ind = lower_bound(arr_cost.begin(),arr_cost.end(),c)-arr_cost.begin();
                if(ind==p){
                    ind = p-1;
                }
                if(arr_cost[ind]>c)ind--;
                if(ind==-1)break;
                ll mn_loss = st.query(0,0,n-1,0,ind);
                ll ind_loss = mp3[mn_loss];
                ll diff = c-arr_cost[ind_loss];
                ll temp = diff/mn_loss + 1;
                c -= temp*mn_loss;
                ans += temp;
            }
        }
        
        ans*=2;
        cout<<ans<<endl;
    }
}