#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {
    long mtype;
    char mtext[9999];
} msgType;

int compare(const void* first,const void*second){
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first <*(int*)second)
        return -1;
    else
        return 0;
    
}

int* addArr(int arr[], int count, int arr2[], int count2){
    for(int i = count; i < count2; i++)
        arr[i] = arr2[i - count];
    return arr;
}

void distribute(int start, int end){

}