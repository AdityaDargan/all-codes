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
    int count[26] = {0};
    bool flag = false;
    int flag_count = 0;
    
    bool check_key(char c){
        return (arr[c-'a']!=NULL);
    }

    void add_key(char c){
        arr[c-'a'] = new node();
        return;
    }

    void increase(char c){
        count[c-'a']++;
    }

    node * next_node(char c){
        return arr[c-'a'];
    }

    void set_last(){
        flag = true;
        flag_count++;
        return;
    }

    int no_of_flag(){
        return flag_count;
    }

    int char_count(char &c){
        return count[c-'a'];
    }

    void erase_char(char &c){
        count[c-'a']--;
        if(count[c-'a']==0){
            arr[c-'a']=NULL;
        }
        return;
    }

    void erase_flag(){
        flag_count--;
        if(flag_count==0)flag=true;
        return;
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
            cur->increase(s[i]);
            cur = cur->next_node(s[i]);
        }
        cur->set_last();
    }

    int countWordsEqualTo(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return 0;
            cur = cur->next_node(s[i]);
        }
        return cur->no_of_flag();
    }

    int countWordsStartingWith(string &s){
        node *cur = root;
        int ret = 0;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return 0;
            if(i==s.length()-1){
                return cur->char_count(s[i]);
            }
        }
    }

    void erase(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            node *temp = cur->next_node(s[i]);
            cur->erase_char(s[i]);
            cur = temp;
        }
        cur->erase_flag();
        return;
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

    }
}