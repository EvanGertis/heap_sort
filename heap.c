#include "stdio.h"
#define LARGE_VALUE 99999

void heapSort(int a[], int size);
void buildHeap_BottomUp(int a[], int n);
int deleteRoot(int a[], int *pn);
void restoreDown(int a[], int i, int n);

int main(){
    int a[50], n;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        printf("Enter element %d : ", i);
        scanf("%d", &a[i]);
    }

    printf("The unsorted array is : \n");
    for(int i = 1; i <= n; i++){
        printf("%d | ", a[i]);
    }

    heapSort(a, n);

    printf("The sorted array is : \n");
    for(int i = 1; i <= n; i++){
        printf("%d | ", a[i]);
    }
    return 0;
}


void heapSort(int a[], int size){
    int max;
    buildHeap_BottomUp(a, size);

    while(size > 1){
        max = deleteRoot(a, &size);
        a[size + 1] = max;
    }
}

void buildHeap_BottomUp(int a[], int n){
    for(int i = n/2; i >= 1; i--){
        restoreDown(a, i , n);
    }
}

int deleteRoot(int a[], int *pn){
    int maxValue = a[1];
    a[1] = a[*pn];
    (*pn)--;
    restoreDown(a, 1, *pn);
    return maxValue;
}

void restoreDown(int a[], int i, int n){
    int k = a[i];
    int lchild = 2* i, rchild = lchild + 1;

    while(rchild <= n){
        if(k >= a[lchild] && k >= a[rchild]){
            a[i] = k;
            return;
        }
        else if(a[lchild] > a[rchild]){
            a[i] = a[lchild];
            i = lchild;
        }
        else{
            a[i] = a[rchild];
            i = rchild;
        }
        lchild = 2*i;
        rchild = lchild+ 1;
    }

    if(lchild == n && k < a[lchild]){
        a[i] = a[lchild];
        i = lchild;
    }
    a[i] = k;
}

