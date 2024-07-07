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

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }

    ll query(ll ind,ll low,ll high,ll l,ll r){
        // No Overlap
        if(l>high || r<low){
            return INT_MAX;
        }
        // Full Overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        // Partial Overlap
        ll mid=(low+high)/2;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
};
// segTree st(n);
// st.build(0,0,n-1,arr);
// st.query(0,0,n-1,l,r)<<endl;
// st.update(0,0,n-1,index,val);
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        segTree st(n);
        st.build(0,0,n-1,arr);

        ll q;
        cin>>q;
        while(q--){
            ll type;cin>>type;
            if(type==1){
                //update list
                ll index,val;
                cin>>index>>val;
                st.update(0,0,n-1,index,val);
            }
            else{
                //get query
                ll l,r;
                cin>>l>>r;
                cout<<st.query(0,0,n-1,l,r)<<endl;
            }
        }
    }
}