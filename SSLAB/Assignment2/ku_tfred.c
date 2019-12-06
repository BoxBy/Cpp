
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 9999

struct t_data{ // 인자로 하나만 보내주고 싶어서 struct 사용
    int start; // == threadNum == 시작숫자
    int end;
    int interval;
    int threadsNum; // threads의 개수
};

void* thread_distribute(struct t_data data){
    for(int start = data.start; start < BUFFER_SIZE; start += data.threadsNum){
        for(int pointer = 1; pointer <= data.interval; pointer++){
            if((int)(buffer[start] / data.interval) == pointer){
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
pthread_mutex_t mutex;
int intervalBuffer[20][BUFFER_SIZE];
int buffer[BUFFER_SIZE] = { 0 };
int count[20];

int main(int argc, char* argv[3]){
    // argv[0] = number of threads
    // argv[1] = interval
    // argv[2] = input file

    FILE* file = fopen(argv[2], "r");

    for(int i = 0; i < BUFFER_SIZE; i++)
        fscanf(file, "%d", &buffer[i]);

    struct t_data data;
    data.threadsNum = atoi(argv[0]);
    data.interval = atoi(argv[1]);
    data.end = BUFFER_SIZE;
    int status;
    pthread_mutex_t_init(&mutex, NULL);




    pthread_t thread_id[data.threadsNum];
    for(int i = 0; i < data.threadsNum; i++){
        data.start = i;
        status = pthread_create(&thread_id[i], NULL, thread_distribute, data);
    }   
    
    for(int i = 0; i < data.interval; i++)
        qsort(intervalBuffer[i], count[i], sizeof(int), compare);
    
    data.start = 0;
    for(int i = 0; i < data.interval; i++){ // 출력
        printf("%d ~ %d = ",data.start, data.start + (int)(BUFFER_SIZE / data.interval));
        for(int j = 0; j < count[i]; j++){
            printf("%d, ", intervalBuffer[i][j]);
        }
    }
}