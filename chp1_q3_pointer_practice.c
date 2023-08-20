#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n=4;

struct double_link
{
    struct double_link *prev;
    char str[100];        
    struct double_link *next;        
};

void display(struct double_link * head){
    while(head!=NULL){
        printf("%s\n",head->str);
        head=head->next;
    }
    printf("\n");
}

struct double_link* insert(char str[100],int position,struct double_link * head){
    struct double_link *new_node=(struct double_link *)malloc(sizeof(struct double_link));
    strcpy(new_node->str,str);
    if(position!=1){
        for(int j=1;j<position;j++){
            if(j==position-1){
                new_node->prev=head;
                new_node->next=head->next;
                head->next->prev=new_node;
                head->next=new_node;
            }
            head=head->next;
        }
        return NULL;
    }
    else if(position==1){
        new_node->prev=NULL;
        new_node->next=head;
        head->prev=new_node;
        strcpy(new_node->str,str);
        return new_node;
    }
    else{
        printf("invalid");
        return NULL;
    }
}

struct double_link* find(char str[100],struct double_link *head){
    while(head!=NULL){
        if(!strcmp(head->str,str)){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

struct double_link* delete(char str[100],struct double_link *head){
    int count=1;
    while(head!=NULL){
        if(!strcmp(head->str,str)){
            if(count==1){
                head->next->prev=NULL;
                struct double_link *temp=head->next;
                free(head);
                return temp;
            }
            else{
                head->prev->next=head->next;
                head->next->prev=head->prev;
                free(head);
                return NULL;
            }
        }
        head=head->next;
        count++;
    }
    return NULL;
}

int main(){
    struct double_link* head=(struct double_link *)malloc(sizeof(struct double_link));
    struct double_link* second=(struct double_link *)malloc(sizeof(struct double_link));
    struct double_link* third=(struct double_link *)malloc(sizeof(struct double_link));
    struct double_link* forth=(struct double_link *)malloc(sizeof(struct double_link));
    head->prev=NULL;
    strcpy(head->str,"head node");
    head->next=second;
    second->prev=head;
    strcpy(second->str,"second node");
    second->next=third;
    third->prev=second;
    strcpy(third->str,"third node");
    third->next=forth;
    forth->prev=third;
    strcpy(forth->str,"forth node");
    forth->next=NULL;
    printf("Displaying nodes already in the linked list\n");
    display(head);
    printf("Inserting new node\n");
    struct double_link *new=insert("new node",1,head);
    if(new!=NULL){
        head=new;
    }
    display(head);
    printf("\n");
    printf("Finding node\n");
    struct double_link *third_node=find("thir node",head);
    if(third_node==NULL){
        printf("node not found!!\n\n");
    }
    else{
        printf("%s\n\n",third_node->str);
    }   
    printf("Deleting node\n");
    new=delete("head node",head);
    if(new!=NULL){
        head=new;
    }
    display(head);
    return 0;
}