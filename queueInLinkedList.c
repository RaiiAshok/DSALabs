#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node
{
    int info;
    struct node *next;
};

typedef struct node nodeType;
nodeType *rear = NULL, *front = NULL;

void insert(int);
void delete();
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
            printf("Enter the data to be enque: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            delete();
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

void insert(int item){
    nodeType *nnode;
    nnode = (nodeType*)malloc(sizeof(nodeType));
    if(rear == NULL){
        nnode->info = item;
        nnode->next = NULL;
        rear = nnode;
        front = nnode;
    }
    else{
        nnode->info = item;
        nnode->next = NULL;
        rear->next = nnode;
        rear = nnode;

    }
}

void delete(){
    nodeType *temp;
    if(front == NULL){
        printf("Queue is Empty");
    }
    else if(front->next == NULL){
        temp = front;
        rear = NULL;
        front = NULL;
        printf("Deleted item is: %d", temp->info);
    }
    else{
        temp = front;
        front = front->next;
        printf("Deleted item is: %d", temp->info);
        free(temp);
    }
}

void display(){
    nodeType *temp;
    if(front == NULL){
        printf("The Queue is empty...");
    }
    else{
        temp = front;
        printf("The items in the queue are: \n");
        while(temp != NULL){
            printf("%d \t", temp->info);
            temp = temp->next;
        }
    }
}