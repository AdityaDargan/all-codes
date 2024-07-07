
//binary search can be applied to find anything in a sorted data in log(n) time complexity 

//answer can be found where low stands at the end after low has crossed high

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int bs(){
    int n = 6;
    int arr[n] = {1,4,5,8,10,11};
    int low = 0;
    int high = n-1;
    int find = 8;
    int mid = (low+high)/2;
    while(low<=high){
        if(arr[mid]>find){
            high = mid-1;
        }
        else if(arr[mid]<find){
            low = mid+1;
        }
        else{
            cout<<mid;
            break;
        }
        mid = (low+high)/2;
    }
}
int main(){
    int n=7;
    int a[n] ={1,3,5,7,7,7,11};
    bool ans = binary_search(a,a+n,3);
    bool ans1 = binary_search(a,a+n,4);
    cout<<ans<<" "<<ans1<<endl;
    //checking if a particular number exists in a array or not


    // (-a) is done to get the index 
    int ind = lower_bound(a,a+n,7)-a;
    //gives first occurence
    int ind1 = lower_bound(a,a+n,6)-a;
    //gives the number just above it 
    int ind2 = lower_bound(a,a+n,12)-a;
    // gives last index + 1 as all elements present are smaller than it.
    cout<<ind<<" "<<ind1<<" "<<ind2<<endl;


    int in = upper_bound(a,a+n,6)-a;
    int in2 = upper_bound(a,a+n,12)-a;
    int in3 = upper_bound(a,a+n,0)-a;
    //always returns the number available which is just greater than searched number
    cout<<in<<" "<<in2<<" "<<in3<<endl;


    //edge case is usually that - 
    //iterator can be > than n in lower bound
    //or iterator can be < than 0 in upper bound
    bs();
    
}