#include <stdio.h>

void PrintList(int list[], int size){
    for(int i=0; i<size; ++i){
        printf("%5d", list[i]);
    }
    printf("\n");
}

int main(){
    int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
    int size = 8;

    PrintList(list, size);

    return 0;
}