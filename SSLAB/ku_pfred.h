#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int compare(const void* first,const void*second){ // for qsort
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first <*(int*)second)
        return -1;
    else
        return 0;
    
}

int* addArr(int firstArr[], int first, int secondArr[], int second){
    for(int i = first; i < second; i++)
        firstArr[i] = secondArr[i - first];
    return firstArr;
}