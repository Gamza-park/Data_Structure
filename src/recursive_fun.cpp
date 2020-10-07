#include <stdio.h>
#include <iostream>

using namespace std;

int Factorial(int n){
    if(n == 1){
        return 1;
    } 
    else{
        return Factorial(n - 1) * n;
    }
}

int Fibonacci(int n){
    if (n == 1) {
        return 1;
    }
    else if ( n == 2 ){
        return 2;
    }
    else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
int _BinarySearch(int arr[], int left, int right, int data){
    if(left <= right){
        int middle = (left + right) / 2;
        if(data < arr[middle]){
            return _BinarySearch(arr, left, right-1, data);
        }
        else if(data > arr[middle]){
            return _BinarySearch(arr, left+1, right, data);
        }
        else{
            return middle;
        }
    }
}
int BinarySearch(int arr[], int size, int data){
    return _BinarySearch(arr, 0, size-1, data);
}

int main(){

    int x = 5;
    int Fac_result = Factorial(x);
    int Fibo_result = Fibonacci(x);

    cout << Fac_result << endl;
    cout << Fibo_result << endl;

    int arr[10] = { 10, 35, 45, 48, 50, 57, 69, 72, 83, 96 };
    int size = 10;

    int idx = BinarySearch(arr, size, 48);
    if(idx != 1){
        cout << idx << " " << arr[idx] << endl;
    }
    
    
    return 0;
}