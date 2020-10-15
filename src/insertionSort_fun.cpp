#include <stdio.h>

void PrintList(int list[], int size){
    for(int i=0; i<size; ++i){
        printf("%5d", list[i]);
    }
    printf("\n");
}


void InsertionSort(int list[], int size){
    int j, value;
    for(int cur = 1; cur<size; cur++){
        value = list[cur];
        for(j = cur-1; j>=0; --j){
            if(list[j] > value){
                list[j+1] = list[j];
            }else{
                break;
            }
        }
        list[j+1] = value;
    }
}

int main(){
    int list[10] = { 20, 70, 80, 50, 60, 90, 40, 30 };
    int size = 8;

    PrintList(list, size);
    InsertionSort(list, size);
    PrintList(list, size);

    return 0;
}