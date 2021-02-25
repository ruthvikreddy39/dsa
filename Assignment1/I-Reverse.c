#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node *next;
}*head,*temp;
//function to print
void printList(struct Node *n){
    while(n != NULL){
        printf("%d", n->data);
        n = n->next;
        if(n != NULL)
            printf(" ");
    }
}
//function to reverse
void reverse(struct Node **head_ref){
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *current = *head_ref;
    while(current != NULL){
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
int main(){
    head = NULL;
    struct Node *new;
    head = (struct Node*)malloc(sizeof(struct Node));
    int d;
    scanf("%d",&d);
    head->data = d;
    head->next = NULL;
    temp = head;
    while(d != -1){
        scanf("%d",&d);
        if(d==-1)
            break;
        else{
            new = (struct Node*)malloc(sizeof(struct Node));
            new->data = d;
            new->next = NULL;
            temp->next = new;
            temp = temp->next;
        }
    }
    reverse(&head);
    printList(head);
    return 0;
}