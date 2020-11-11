#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct  _node* link;    
} Node;

Node* AllocNode(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = NULL;

    return n; 
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    Node* n;

    n = AllocNode(10);
    tail = head = n;

    n = AllocNode(20);
    tail->link = n;
    tail = n;

    n = AllocNode(30);
    tail->link = n;
    tail = n;
    
    Node* p = head;
    p = p->link;
    Node* pp = p;
    p = p->link;
    // p노드 삭제
    Node* np = p->link;
    pp->link = np;
    free(p);


    for(Node* p = head; p != NULL; p = p->link)
        printf("%d\n", p->data);
    
    for(Node* p = head; p != NULL;){
        Node* np = p->link;
        free(p);
        p = np;
    }

    return 0;
}