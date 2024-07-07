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
    vector<ll> seg;
    vector<ll> lazy;

public:
    segTree(ll n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
        fill(lazy.begin(),lazy.end(),0);
    }

    void build(ll ind,ll low, ll high, vector<ll> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
        return;
    }

    //update like add +4 from (3 - 5) range.
    void updateRange(ll ind,ll low,ll high, ll l,ll r, ll val){    

        //update previous changes
        seg[ind] += lazy[ind]*(high-low+1);
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];
        //No overlap
        if(l>high || r<low){
            return;
        }
        //Full overlap
        if(low>=l && high<=r){
            seg[ind]+=(high-low+1)*val;
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
            return;
        }
        //Partial overlap
        ll mid=(low+high)/2;
        updateRange(2*ind+1,low,mid,l,r,val);
        updateRange(2*ind+2,mid+1,high,l,r,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    
    ll query(ll ind, ll low, ll high, ll l, ll r){
        //previous update
        seg[ind] += lazy[ind]*(high-low+1);
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];   

        //No overlap
        if(l>high || r<low){
            return 0;
        }
        //Full overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        //Partial Overlap
        ll mid=(low+high)/2;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        
    }
}

// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;cin>>n;
//         vector<ll> arr(n);
//         for(ll i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         segTree st(n);
//         st.build(0,0,n-1,arr);
//         ll q;
//         cin>>q;
//         while(q--){
//             ll type;cin>>type;
//             if(type==1){
//                 //update list
//                 ll l,r,val;
//                 cin>>l>>r>>val;
//                 st.updateRange(0,0,n-1,l,r,val);
//             }
//             else{
//                 //get query
//                 ll l,r;
//                 cin>>l>>r;
//                 cout<<st.query(0,0,n-1,l,r)<<endl;
//             }
//         }
//     }
// }