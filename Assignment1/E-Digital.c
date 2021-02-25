#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node* next;
    struct Node* prev;
}*head;
//functions to perform tasks
void printList(struct Node *n){
    while(n != NULL){
        printf("%c", n->data);
        n = n->next;
    }
}
void lr(struct Node **head_ref){
    struct Node *current = *head_ref;
    struct Node *next;
    struct Node *right = current;
    //finding the rightmost node
    while(right->next != NULL)
        right = right->next;
    right->next = current;
    *head_ref = current->next;
    current->next = NULL;
}
void rr(struct Node **head_ref){
    struct Node *current = *head_ref;
    struct Node *next,*prev;
    prev = NULL;
    struct Node *right = current;
    while(right->next != NULL){
        prev = right;
        right = right->next;
    }
    right->next = current;
    *head_ref = right;
    prev->next = NULL;
}
void ls(struct Node **head_ref){
    lr(head_ref);
    struct Node *current = *head_ref;
    struct Node *right = current;
    while(right->next != NULL)
        right = right->next;
    right->data = 0 + '0';
}
void rs(struct Node **head_ref){
    rr(head_ref);
    struct Node *current = *head_ref;
    current->data = 0 + '0';
}
void inc(struct Node **head_ref){
    char carry='0';
    char sum,last;
    struct Node *current = *head_ref;
    struct Node *right = current;
    while(right->next != NULL)
        right = right->next;
    /*sum=right->data+'1';
    if(sum=='a')
        right->data='1';
    else if(sum=='b'){
        right->data='0';
        carry='1';
    }
    right=right->prev;
    while(right != NULL){
        sum=right->data+carry;
        if(sum=='a'){
            right->data='1';
            carry='0';
        }
        else if(sum=='b'){
            right->data='0';
            carry='1';
        }
        right= right->prev;
    }*/
    sum=right->data+'1';
    if(sum== 'a'){
        right->data='1';
        carry='0';
    }
    else if(summ == 'b'){
        
    }
    
    printf("%c\n",carry);
    right=right->prev;
    if(last == 1){
        while(right != NULL){
            sum = (right->data+'0'+carry);
            carry = (sum)/2;
            right->data=(sum%2)+'0';           
            right=right->prev;
        }
    }
}
void  dec(struct Node **head_ref){
    char carry='0';
    char sum;
    struct Node *current = *head_ref;
    struct Node *right = current;
    while(right->next != NULL)
        right = right->next;
    sum=right->data+'1';
    printf("%c\n",sum);
    right->data = (right->data+'1')%2+'0';
    right=right->prev;
    printf("%c\n",carry);
    while(right!=NULL){
        sum = (right->data+'1'+carry);
        carry = (sum+'0')/2;
        right->data=(sum%2)+'0';           
        right=right->prev;
    }
}
int main(){

    char b[1000],c[3];
    scanf("%s",b);
    int t;
    //scanf("%d",&t);

    head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *new, *temp;
    head->data = b[0];
    head->next = NULL;
    head->prev = NULL;
    temp=head;
    for(int i=1; i<strlen(b); i++){
        new = (struct Node*)malloc(sizeof(struct Node));
        new->data = b[i];
        new->next = NULL;
        new->prev = NULL;
        temp->next = new;
        temp = temp->next;
    }
    //lr(&head);
    //rr(&head);
    //ls(&head);
    //rs(&head);
    //inc(&head);
    dec(&head);
    printList(head);
    return 0;
}