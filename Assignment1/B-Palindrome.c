//checking if palindrom or note using only doubly linked lists
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node* next;
    struct Node* prev;
}*head;

void printList(struct Node *n){
    while(n != NULL){
        printf("%c", n->data);
        n = n->next;
    }
}

void palindrome(struct Node* left){

    struct Node *right = left;
    //finding the rightmost node
    while(right->next != NULL)
        right = right->next;
    //comparing the letters
    while(left!=right){
        if(left->data!=right->data){
            printf("NOT A PALINDROME");
            exit(0);
        }
        left = left->next;
        right = right->prev;
    }
    printf("PALINDROME");
}
int main(){

    int n;
    scanf("%d",&n);
    char s[1000];
    scanf("%s",s);
    head = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *new,*temp;
    head->data = s[0];
    head->prev = NULL;
    head->next = NULL;

    temp = head;
    for(int i=2;i<=n;i++){
        new = (struct Node*)malloc(sizeof(struct Node));
        new->data = s[i-1];
        new->prev = temp;
        new->next = NULL;

        temp->next = new;
        temp = temp->next;
    }
    palindrome(head);
    return 0;
}