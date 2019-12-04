#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct t_data{ // 인자로 하나만 보내주고 싶어서 struct 사용
    int start; // == threadNum == 시작숫자
    int end;
    int interval;
    int threadsNum; // threads의 개수
}

void* thread_distribute(struct t_data data){
    for(int start = data.start; start < BUFFER_SIZE; start += data.threadsNum){
        for(int pointer = 1; pointer <= data.interval; pointer++){
            if((int)(buffer[start] / interval) == pointer){
                pthread_mutex_lock(&mutex);
                intervalBuffer[pointer][count[pointer]] = buffer[start];
                count[pointer]++;
                pthread_mutex_unlock(&mutex);
            }
        }
    }
    return NULL;
}

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