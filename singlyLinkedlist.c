// singly Linkedlist with insert delete and insert operation
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct node
{
    int info;
    struct node *next;
};

typedef struct node NodeType;
NodeType *first = NULL, *last = NULL;
int count;
// first = NULL;
// last = NULL;

void insert(int);
void delete();
void display();

int main(){
    int choice, item;
    do{
        printf("\nPress 1 for Insertion\nPress 2 for Deletion\nPress 3 for display\nPress 4 to exit\n");
        printf("Enter your Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted: ");
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
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }while(choice != 4);

}


void insert(int item){
    int pos, i;
    NodeType *newNode, *temp;
    newNode->info = item;
        printf("Enter the position to be inserted at:");
        scanf("%d", &pos);
        printf("%d====",count);

    if(first == NULL){
        first = newNode;
        last = newNode;
        // newNode->next = NULL;
        // count++;
        // printf("%d====",count);
    }
    else{
        // if(count < pos){
        //     printf("Enter the node to be inserted at less than %d\n", count);
        //     insert(item);
        // }
        // else{
            // printf("Hell");
            temp = first;
        for(i = 1; i <(pos-1); i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        // }
    }
}

void delete(){
    NodeType *hold, *temp;
    int pos, i;
    if(first == NULL){
        printf("NO node");
    }
    else{
        temp = first;
        printf("Enter the position to be deleted at: ");
        scanf("%d", &pos);
        for(i = 1; i <(pos - 1); i++){
            temp = temp->next;
        }
        hold = temp->next;
        temp->next = hold->next;
        free(hold);
    }
}

void display(){
    NodeType *temp;
    if(first == NULL){
        printf("Empty node");
    }
    else{
        temp = first;
        int c = 0;
        while(temp != NULL){
            printf("The info is: %d\n", temp->info);
            temp = temp->next;
        }
    }

}