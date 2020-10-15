#include <stdio.h>

void PrintList(int list[], int size){
    for(int i=0; i<size; ++i){
        printf("%5d", list[i]);
    }
    printf("\n");
}

void Swap(int* pa, int* pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int Min(int list[], int sIndex, int eIndex){
    int min = sIndex;
    for(int i = sIndex + 1; i <= eIndex; ++i){
        if(list[min] > list[i]){
            min = i;
        }
    }
    return min;
}
void SelectionSort(int list[], int size){
    for(int i=0; i< size-1; ++i){
        int min=Min(list, i, size-1);
        // printf("%d \n", list[min]);
        Swap(&list[i], &list[min]);
    }
}

int main(){
    int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
    int size = 8;

    PrintList(list, size);
    SelectionSort(list, size);
    PrintList(list, size);

    return 0;
}