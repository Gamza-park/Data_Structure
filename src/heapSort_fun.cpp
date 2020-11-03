#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void Swap(int* pa, int* pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void PrintList(int list[]){
    printf("size: %d", list[0]);
    printf("  [");
    for(int i=1; i<= list[0]; ++i){
        printf("%d ", list[i]);
    }

    printf("] ");
    for(int i=list[0]+1; i<=8; ++i){
        printf("%d ", list[i]);
    }
    printf("\n");
}

void Push_heap(int list[]){
    ++list[0];
    int size = list[0];
    int child = size;
    int parent = child / 2;
    while(parent > 0){
        if(list[parent] < list[child]){
            Swap(&list[parent], &list[child]);
        }
        else{
            break;
        }
        child = parent;
        parent = child / 2;
    }
}

void Make_heap(int list[], int size){
    for(int i=0; i<size; ++i){
        Push_heap(list);
    }
}

void Pop_heap(int list[]){
    int size = --list[0];
    Swap(&list[1], &list[size + 1]);
    int parent = 1;
    int child = parent * 2;

    while(child <= size){
        if(child < size && list[child] < list[child + 1]){
            child = child + 1;
        }
        if(list[parent] < list[child]){
            Swap(&list[parent], &list[child]);
        }
        parent = child;
        child = parent * 2;
    }
}

void Sort_heap(int list[]){
    int size = list[0];
    for(int i=0; i<size; ++i){
        Pop_heap(list);
    }
}

int main(){
    int list[10] = { 5, 70, 45, 35, 15, 20, 85, 75, 55 };
    
    PrintList(list);
    Make_heap(list, 8);
    Sort_heap(list);
    PrintList(list);
}