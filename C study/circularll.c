#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * node;
};

struct node * insert(struct node *head){

    printf("\n Enter no of inputs: ");
    int n;
    scanf("%d",&n);

    if(n>0 && head==NULL){
        head=(struct node *)malloc(sizeof(struct node));
        int hdata;
        scanf("%d",&hdata);
        head->data = hdata;
        head->node = head;
        n--;
    }

    struct node * prev = head;
    while(prev->node!=head){
        prev=prev->node;
    }

    for(int i=0;i<n;i++){
        struct node * new = (struct node* )malloc(sizeof(struct node));

        prev->node=new;
        int ndata;
        scanf("%d",&ndata);
        new->data=ndata;

        prev=new;
    }
    prev->node=head;
    return head;
}

void display(struct node * head){
    struct node * ptr=head;
    while(1){
        printf("%d",ptr->data);
        if(ptr->node==head){
            break;
        }
        ptr=ptr->node;
    }
    return;
}

struct node* delfirst(struct node* head){
    struct node* ptr=head;
    while(ptr->node!=head){
        ptr=ptr->node;
    }
    head=head->node;
    free(ptr->node);
    ptr->node=head;
    return head;
}

struct node* dellast(struct node* head){
    struct node* ptr=head;
    while((ptr->node)->node!=head){
        ptr=ptr->node;
    }

    free(ptr->node);
    ptr->node=head;
    return head;
}

struct node* delindex(struct node* head,int index){
    struct node* ptr=head;
    for(int i=0;i<index-2;i++){
        ptr=ptr->node;
    }
    if(ptr->node==head){
        head=ptr->node->node;
        free(ptr->node);
        ptr->node=head;
    }
    else if(ptr->node->node==head){
        ptr->node=head;
        free(ptr->node);
    }
    else{
        struct node* p=ptr->node;
        ptr->node = p->node;
        free(p);
    }
    return head;
}

struct node* delvalue(struct node* head,int val){
    struct node* ptr=head;
    while((ptr->node)->data!=val){
        ptr=ptr->node;
    }
    struct node* p=ptr->node;
    ptr->node=p->node;
    free(p);
    return head;
}

struct node* delete(struct node* head){
    printf("\n 1.delete last element \n 2. delete 1st element \n 3. delete indexed element(1st index=1) \n 4. delete by value \n Enter your option : ");
    int del;
    scanf("%d",&del);
    switch(del){
        case(1):
            return dellast(head);
            break;
        case(2):
            return delfirst(head);
            break;
        case(3):
            printf("enter index: ");
            int index;
            scanf("%d",&index);
            return delindex(head,index);
            break;
        case(4):
            printf("enter index: ");
            int val;
            scanf("%d",&val);
            return delvalue(head,val);
            break;
    }
}

int main(){

    struct node * head = NULL;

    int check=1;
    while(check){
        printf("\n 1. insert \n 2. display \n 3. delete \n 4. exit \n Enter Your Option: ");

        int opt;
        scanf("%d",&opt);

        switch(opt){
            case(1):
                head = insert(head);
                break;
            case(2):
                display(head);
                break;
            case(3):
                head = delete(head);
                break;
            case(4):
                check=0;
                break;
        }
    }
}
