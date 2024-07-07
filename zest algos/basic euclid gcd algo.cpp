#include <bits/stdc++.h>

using namespace std;

// uses the property that gcd (12,8) = gcd(8,12%8) = gcd(8,4)

/*
    gcd(a,b) = gcd(b%a,a)
    proof -> 
    let us assume b>a in this => (f>e)
    let a = g*e
    let b = g*f
    now their gcd is g;

    as b>a 
    so we can write b = a*x + c
    so g*f = g*e*x + c
    => c = g*(f-ex)
    so c would also have g as its factor 

    and c = b%a

    => gcd(a,b) [where b>a] = gcd(b%a,a);
    and now (b%a < a) => a recursive call

    TC = O(log(min(a,b)))
*/


// now in this case we have assumed b>a
// but if given is a>b so b%a = b so in next recursion call we can send min,max as a,b and again b>a becomes

int cal_gcd(int a,int b){
    if(a==0)return b;
    return cal_gcd(b%a,a);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<cal_gcd(a,b)<<endl;
    }
}