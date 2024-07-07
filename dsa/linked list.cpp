#include <iostream>
#include <vector>
using namespace std;


class node{
    public:
    int data;
    node *next;

    node(int input_data){
        this->data = input_data;
        this->next = NULL;
    }
};

int main(){
    node *temp = new node(10);
    cout<< temp->data << " " << temp->next << endl;
    node *temp2 = new node(20);
    temp->next = temp2;
    cout<< temp->data <<" "<< (temp->next)->data<<endl;
}