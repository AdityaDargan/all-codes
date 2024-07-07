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

class node{
    public:
    node * arr[26];
    bool flag = false;
    
    bool check_key(char &c){
        return (arr[c-'a']!=NULL);
    }

    void add_key(char &c){
        arr[c-'a'] = new node();
        return;
    }

    node * next_node(char &c){
        return arr[c-'a'];
    }

    void set_last(){
        flag = true;
        return;
    }
    
    bool is_last(){
        return flag;
    }
};

class Trie{
    public:
    node* root;

    // initialize 
    Trie(){
        root = new node();
    }

    void insert(string &s){
        node* cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check){
                cur->add_key(s[i]);
            }
            cur = cur->next_node(s[i]);
        }
        cur->set_last();
    }

    bool search(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return false;

            cur = cur->next_node(s[i]);
        }
        return cur->is_last();
    }

    bool startswith(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check)return false;
            cur = cur->next_node(s[i]);
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        Trie tr;
        string a = "hello";
        string b = "xbcd";
        string c = "cdba";
        string d = "heli";
        string e = "heliiico";
        string f = "helo";

        tr.insert(a);
        tr.insert(b);
        cout<<tr.search(c)<<endl;
        cout<<tr.search(a)<<endl;
        cout<<tr.startswith(d)<<endl;
        tr.insert(c);
        tr.insert(e);
        cout<<tr.search(c)<<endl;
        cout<<tr.startswith(d)<<endl;
        cout<<tr.startswith(f)<<endl;
    }
}