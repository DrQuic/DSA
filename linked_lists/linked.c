#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int value;
    void *next;
} Node;

void printNode(Node *node) {
    printf("{\n");
    printf("    value :%d\n", node->value);
    printf("    next  :%p\n", node->next);
    printf("}\n");
}


void printList(Node *node, bool asStruct) {
    while(node != NULL) {
        if (asStruct) {
            printNode(node);
        } else {
            printf("%d->", node->value);
        }
        node = node->next;
    }
    printf("\n");
}

Node* createNode(int value) {
   Node *newNode = malloc(sizeof(Node));
   newNode->value = value;
   newNode->next = NULL;
   return newNode;
}

Node* addNode(Node *head, int value) {
    Node* newNode = createNode(value);
    if(head->next != NULL) {
       newNode->next = head->next;
    }
    head->next = newNode;
    return newNode;
}

Node* findElement(Node *node, int value) {
    Node *current = node;
    while(current != NULL){
        if(current->value == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* appendNode(Node *node, int value){
    Node* newNode = createNode(value);
    while(node->next != NULL) {
        node = node->next;
    }
    printNode(node);

    node->next = newNode;
    return newNode;
}

void linkedListCollector(Node *head) {
    if(head->next == NULL) {
        free(head);
        return;
    }
    
    linkedListCollector(head->next);
    free(head);
}

bool deleteNode(Node *currentNode, Node *node) {
    while (currentNode != NULL) {
        if(currentNode->next == node){
            currentNode->next = node->next;
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

int linkedListLength(Node *head) {
   Node *current = head;
   int count = 0;
    
   while(current != NULL) {
        printNode(current);
        current = current->next;
        count++;
    }

   return count;

}

int main() {
    Node* head = createNode(1);
    Node* node1 = addNode(head, 2);
    Node* node2 = addNode(head, 3);
    Node * node3 = appendNode(head, 4);
    int count = linkedListLength(head);
    printf("==== %d", count);
    linkedListCollector(head);
    return 0;
}
