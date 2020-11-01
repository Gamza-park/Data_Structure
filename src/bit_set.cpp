#include <stdio.h>

typedef unsigned long BitSet; // 집합 형식

#define BitSetNull (BitSet)0 // 공집합
#define BitSetBits 32 // 유효 비트 수
#define SetOf(no) ((BitSet)1 << (no)) // 집합 {no}

// 집합 원소 확인
int IsMember(BitSet s, int data);
// 집합 원소 추가
void Add(BitSet* s, int data);
// 집합 원소 삭제
void Remove(BitSet* s, int data);
// 집합 개수 반환
int Size(BitSet s);
// 집합 원소 출력
void Print(BitSet s);

int IsMember(BitSet s, int data){
    return s & SetOf(data);
}

void Add(BitSet* s, int data){
    *s |= SetOf(data);
}

void Remove(BitSet* s, int data){
    *s &= ~SetOf(data);
}

int Size(BitSet s){
    int count = 0;
    for( ; s!=BitSetNull; ++count){
        s &= s - 1;
    }
    return count;
}

void Print(BitSet s){
    printf("{ ");
    for(int i=0; i<BitSetBits; ++i){
        if(IsMember(s, i)){
            printf("%d ", i);
        }
    }
    printf("}");
}

int main(){
    BitSet A = BitSetNull;

    Add(&A, 1);
    Add(&A, 3);
    Add(&A, 5);

    Remove(&A, 3);
    printf("size : %d\n", Size(A));

    Print(A);
}