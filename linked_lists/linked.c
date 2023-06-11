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
        current = current->next;
        count++;
    }

   return count;

}

Node* reverse(Node *node) {
   Node* prev = NULL;
   while(node != NULL) {
        Node* nextTemp = node->next;
        node->next = prev;
        prev = node;
        node = nextTemp;
   }
   return prev;
}

void swapNodeValues(Node* node1, Node* node2) {
   int nodeValue = node1->value;
   node1->value = node2->value;
   node2->value = nodeValue;
}


Node* partition(Node* head, Node* tail) {
    Node* minHead = head;
    Node* prev = head;
    while(head != NULL){
       if (head->value < tail->value) {
           swapNodeValues(minHead, head);
           prev = minHead; 
           minHead = minHead->next;
       }
       head = head->next;
    }

    swapNodeValues(minHead->next, tail);
    return prev;
}


int main() {
    Node* head = createNode(10);
    Node* node1 = appendNode(head, 80);
    Node* node2 = appendNode(head, 30);
    Node* node3 = appendNode(head, 90);
    Node* node4 = appendNode(head, 40);
    printList(head, false);
    partition(head, node4);
    printList(head, false);
    linkedListCollector(head);
    return 0;
}
