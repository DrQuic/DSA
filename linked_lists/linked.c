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

void printList(Node *node) {
    printNode(node);
    if(node->next == NULL){
        return;
    }
    node = node->next;
    printList(node);
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
    if(node->value == value){
        return node;
    }

    if(node->next == NULL) {
        return NULL;
    }

    findElement(node->next, value);
}

Node* appendNode(Node *node, int value){
    if(node->next == NULL){
        Node* newNode = createNode(value);
        node->next = newNode;
        return newNode;
    }
    appendNode(node->next, value);
}

void linkedListCollector(Node *head) {
    if(head->next == NULL) {
        free(head);
        return;
    }
    
    linkedListCollector(head->next);
    free(head);
}

bool deleteNode(Node *head, Node *node) {
    if(head->next == node) {
        head->next = node->next;
        free(node);
        return true;
    }
    
    deleteNode(head->next, node);
    return false;
}

int linkedListLength(Node *head, int count) {
    count++;
    if(head->next == NULL) {
        return count;
    }

    linkedListLength(head->next, count);
}


int main() {
    Node* head = createNode(1);
    Node* node2 = appendNode(head, 2);
    Node* node3 = appendNode(head, 3);
    Node* node4 = appendNode(head, 4);
    printList(head);
    deleteNode(head, node3);
    printf("====================================================================");
    printList(head);
    linkedListCollector(head);
}
