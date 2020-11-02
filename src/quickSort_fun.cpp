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

void _Sort(int list[], int left, int right){
    if(left <= right){
        int pivot = left;
        int i = left + 1;
        int j = right;
        do{
            while(list[pivot] > list[i]){
                ++i;
            }
            while(list[pivot] < list[j]){
                --j;
            }
            if(i <= j){
                Swap(&list[i], &list[j]);
                ++i;
                --j;
            }
        }while(i<=j);
        Swap(&list[pivot], &list[j]);
        _Sort(list, left, j-1);
        _Sort(list, j+1, right);
    }
}

void Sort(int list[], int size){
    _Sort(list, 0, size - 1);
}

int main(){
    int list[10] = {50, 20, 70, 80, 60, 90, 40, 30, 45, 75};
    int size = 10;

    Sort(list, size);

    PrintList(list, size);
}