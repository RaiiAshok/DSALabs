// Stack implementation in Linkedlist

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node
{
    int info;
    struct node *next;
};

typedef struct node nodeType;
nodeType *top=NULL;
void push(int);
void pop();
void display();

int main(){
    int choice, item;
    do
    {
        printf("\nEnter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter 4 to exit");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
            break;        
        default:
            printf("Enter valid choice.");
            break;
        }
    } while (choice != 4);
    
}

void push(int item){
    nodeType *nnode;
    int data;
    nnode = (nodeType*)malloc(sizeof(nodeType));
    if(top == NULL){
        nnode->info = item;
        nnode->next = NULL;
        top = nnode;
    }
    else{
        nnode->info = item;
        nnode->next = top;
        top = nnode;
    }
}

void pop(){
    nodeType *temp;
    if(top == NULL){
        printf("Stack Empty");
    }
    else{
        temp = top;
        top = top ->next;
        printf("The deleted item: %d", temp->info);
        free(temp);
    }
}

void display(){
    nodeType *temp;
    if(top == NULL){
        printf("Stack is empty");
    }
    else{
        temp = top;
        printf("The items in the stack are:\n");
        while(temp != NULL){
            printf("%d\t", temp->info);
            temp = temp->next;
        }
    }
}