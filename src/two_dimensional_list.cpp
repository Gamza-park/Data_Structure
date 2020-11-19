#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    _node* prev;
    _node* next;
} Node;

Node* AllocNode(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n -> data = data;
    n -> prev = NULL;
    n -> next = NULL;
    return n;
}

void FreeNode(Node* p){
    free(p);
}

void AddTailList(Node* head, Node* tail, int data){
    Node* n = AllocNode(data);
    Node* ptail = tail->prev;

    ptail->next = n;
    n->prev = ptail;
    n->next = tail;
    tail->prev = n;
}

void AddHeadList(Node* head, Node* tail, int data){
    Node* n = AllocNode(data);
    Node* nhead = head->next;

    head->next = n;
    n->prev = head;
    n->next = nhead;
    nhead->prev = n;
}

void RemoveList(Node* head, Node* tail, Node* p){
    Node* pp = p->prev;
    Node* np = p->next;
    pp->next = np;
    np->prev = pp;
    free(p);
}

void RemoveTailList(Node* head, Node* tail){
    RemoveList(head, tail, tail->prev);
}

void RemoveHeadList(Node* head, Node* tail){
    RemoveList(head, tail, head->next);
}

void InitList(Node** phead, Node** ptail){
        *phead = AllocNode(0);
        *ptail = AllocNode(0);

        (*phead)->next = *ptail;
        (*ptail)->prev = *phead;
}

void UninitList(Node** phead, Node** ptail){
        for(Node* p=*phead; p!=NULL;){
            Node* np = p->next;
            free(p);
            p = np;
        }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    InitList(&head, &tail);

    Node* n = NULL;
    n = AllocNode(10);
    Node* ptail = tail->prev;
    ptail->next = n;
    n->prev = ptail;
    n->next = tail;
    tail->prev = n;

    n = AllocNode(20);
    ptail = tail->prev;
    ptail->next = n;
    n->prev = ptail;
    n->next = tail;
    tail->prev = n;

    AddTailList(head, tail, 30);

    n = AllocNode(40);
    ptail = tail->prev;
    ptail->next = n;
    n->prev = ptail;
    n->next = tail;
    tail->prev = n;

    n = AllocNode(50);
    ptail = tail->prev;
    ptail->next = n;
    n->prev = ptail;
    n->next = tail;
    tail->prev = n;

  
    for(Node* p = head->next; p != tail; p = p->next){
        printf("%d\n", p->data);
    }

    UninitList(&head, &tail);

    return 0;
}