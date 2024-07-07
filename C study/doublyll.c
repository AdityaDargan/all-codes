#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* insert(struct node* head){
    printf("enter no. of inputs : ");
    int n;
    scanf("%d",&n);
    if(n>0 && head==NULL){
        head=(struct node*)malloc(sizeof(struct node*));

        int hdata;
        scanf("%d",&hdata);
        head->data=hdata;
        head->next=NULL;
        head->prev=NULL;
        n--;
    }
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    for(int i=0;i<n;i++){
        struct node * new = (struct node*)malloc(sizeof(struct node*));
        ptr->next=new;
        new->prev=ptr;

        int temp;
        scanf("%d",&temp);
        new->data=temp;
        ptr=new;
    }
    ptr->next=NULL;

    printf("press 1 to keep adding : ");
    int ques;
    scanf("%d",&ques);
    if(ques==1){
        head = insert(head);
    }
    else{
        return head;
    }
}

void display(struct node* head){
    struct node* ptr=head;
    while(ptr->next!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    printf("\n");
    return;
}

struct node* deleteindex(struct node* head){
    printf("enter index to delete: ");
    int index;
    scanf("%d",&index);
    struct node* ptr=head;

    if(index==1){
        ptr->next->prev=NULL;
        head=ptr->next;
        free(ptr);
    }
    else{
        for(int i=0;i<index-2;i++){
            ptr=ptr->next;
        }
        if(ptr->next->next==NULL){
            free(ptr->next);
            ptr->next=NULL;
        }
        else{
            struct node* p=ptr->next;
            ptr->next = p->next;
            p->next->prev = ptr;
            free(p);
        }
    }
    int ques;
    printf("delete more ? press 1 :");
    scanf("%d",&ques);
    if(ques==1){
        head = deleteindex(head);
    }
    return head;

}

struct node* insertindex(struct node* head){
    printf("enter index to insert: ");
    int index;
    scanf("%d",&index);
    int dat;
    printf("enter data: ");
    scanf("%d",&dat);

    if(index==1){
        struct node* ptr=(struct node*)malloc(sizeof(struct node*));
        ptr->data=dat;

        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
    else{
        struct node* ptr=(struct node*)malloc(sizeof(struct node*));
        ptr->data=dat;
        struct node* p=head;
        for(int i=0;i<index-2;i++){
            p = p->next;
        }
        ptr->prev=p;
        ptr->next=p->next;
        p->next->prev=ptr;
        p->next=ptr;
    }

    int ques;
    scanf("insert more ? press 1 : %d",&ques);
    if(ques==1){
        head = insertindex(head);
    }
    return head;
}

struct node* reverse(struct node* head){
    struct node* ptr=head;
    while(ptr->next!=NULL){
        struct node* p=ptr->next;
        struct node* temp=ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = temp;
        ptr=p;
    }
    ptr->next=ptr->prev;
    ptr->prev = NULL;
    head = ptr;
    return head;
}

int main(){
    struct node* head=NULL;
    head = insert(head);
    display(head);
    head = deleteindex(head);
    display(head);
    head = insertindex(head);
    display(head);
    head = deleteindex(head);
    display(head);
    head = reverse(head);
    display(head);
    head = deleteindex(head);
    display(head);
}