#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int start, int high){
    if(start < high){
        int i = start;
        int j = high;
        int pivo = arr[(i + j)/2];
        while(i <= j){
            while(arr[i] < pivo){
                i ++;
            }
            while(arr[j] > pivo){
                j --;
            }
            if(i <= j){
                int x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
                i ++;
                j --;
            }
        }
        if(i < high){
            quicksort(arr, i, high);
        }
        if(start < j){
            quicksort(arr, start, j);
        }
    }
}

void viewList(int arr[], int tam){
    for(int i = 0; i < tam; i ++){
        printf("|%d|",arr[i]);
    }
}

int main(){

    int arr[] = {21,75,213,97,453,987,32,76,4,9,10,12,43};
    int tam = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,tam - 1);
    viewList(arr,tam);




    return 0;
}
