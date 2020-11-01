#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct
{
    int capacity; // 집합의 최대 크기
    int size; // 원소의 개수
    int* buf; // 집합 배열의 주소
} Set;
// 집합 초기화
int Initialize(Set* s, int cap);
// 집합 원소 확인
int IsMember(const Set* s, int data);
// 원소 추가
void Add(Set* s, int data);
// 원소 삭제
void Remove(Set* s, int data);
// 집합의 저장 가능 최대 원소의 개수
int Capacity(const Set* s);
// 원소의 개수
int Size(const Set* s);
// 집합 s２를 s１에 대입
void Assign(Set* s1, Set* s2);
// 집합 s１、s２가 같은 집합인지 확인
int Equal(const Set* s1, const Set* s2);
// 집합 s2, s3을 합집합을 s1에 대입
Set* Union(Set* s1, const Set* s2, const Set* s3);
// 집합 s2, s3을 교집합을 s1에 대입
Set* Intersection(Set* s1, const Set* s2, const Set* s3);
// 집합 s2-s3의 차집합을 s1에 대입
Set* Difference(Set* s1, const Set* s2, const Set* s3);
// 집합의 모든 원소 출력
void Print(const Set* s);
// 메모리에서 집합 제거
void Terminate(Set* s);

int Initialize(Set* s, int cap){
    s -> capacity = cap;
    s -> size = 0;
    s -> buf = (int*)malloc(sizeof(int)* cap);

    return 0; // Succes = 0 / Failed = -1
}

void Terminate(Set* s){
    free(s -> buf);
    s -> capacity = s -> size = 0;
}

void Add(Set* s, int data){
    if(IsMember(s, data) != -1) return; // 원소 중복 방지
    
    if(s -> size < s -> capacity){
        s -> buf[s -> size++] = data;
    }
}

void Print(const Set* s){
    cout << "size : " << s -> size << ",";
    cout << "    { ";
    for(int i=0; i<s->size; ++i){
        cout << s->buf[i] << " ";
    }
    cout << "}" << endl;
}
int IsMember(const Set* s, int data){
    for(int i=0; i<s->size; ++i){
        if(data == s->buf[i]){
            return i;
        }
    }
    return -1; // 데이터원소가 존재하지 않을 경우
}

void Remove(Set* s, int data){
    int index;
    if((index = IsMember(s,data)) != -1)
    s -> buf[index] = s -> buf[--s -> size];
}

int Capacity(const Set* s){
    return s -> capacity;
}

int Size(const Set* s){
    return s -> size;
}

void Assign(Set* s1, const Set* s2){
    int max = s1 -> capacity < s2 -> size ? s1 -> capacity : s2 -> size;
    for(int i=0; i<max; ++i){
        s1 -> buf[i] = s2 -> buf[i];
    }
    s1 -> size = max;
}

int Equal(const Set* s1, const Set* s2){
    for(int i=0; i<s1 -> size; ++i){
        int j;
        for(j=0; j<s2 ->size; ++j){
            if(s1 -> buf[i] == s2 -> buf[j]){
                break;
            }
        }
        if(j == s2 -> size){
            return 0;
        }
    }
    return 1;
}

Set* Union(Set* s1, const Set* s2, const Set* s3){
    Assign(s1, s2);
    for(int i=0; i<s3->size; ++i){
        Add(s1, s3->buf[i]);
    }
    return s1;
}

Set* Intersection(Set* s1, const Set* s2, const Set* s3){
    s1 -> size = 0; // s1 init
    for(int i=0; i<s2->size; ++i){
        for(int j=0; j<s3->size; ++j){
            if(s2->buf[i] == s3->buf[j]){
                Add(s1, s2->buf[i]);
            }
        }
    }
    return s1;
}

Set* Difference(Set* s1, const Set* s2, const Set* s3){
    for(int i=0; i<s2->size; ++i){
        int j;
        for(j=0; j<s3->size; ++j){
            if(s2->buf[i] == s3->buf[j]){
                break;
            }
        }
        if( j == s3->size){
            Add(s1, s2->buf[i]);
        }
    }
    return s1;
}

int main(){
    // Test
    Set A;
    Set B;
    Set C;
    Initialize(&A, 10);
    Initialize(&B, 10);
    Initialize(&C, 10);
    
    for(int i=1; i<=5; i++){
        if(i%2==1){
            Add(&A, i); // 1, 3, 5
        }
    }
    Add(&B, 1);
    Add(&B, 4);
    Add(&B, 6);
    Intersection(&C,&A,&B);
    // Difference(&C,&A,&B);
    // Union(&C,&A,&B);
    Print(&A);
    Print(&B);
    Print(&C);
    
    // cout << Equal(&A, &B) << endl;

    Terminate(&A);
    Terminate(&B);
    return 0;
}