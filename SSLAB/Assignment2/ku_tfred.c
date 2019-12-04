#include "ku_tfred.h"
#define BUFFER_SIZE 9999

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
    for(int i = 0; i < data.interval; i++){ // Ãâ·Â
        printf("%d ~ %d = ",start, start + (int)(BUFFER_SIZE / data.interval));
        for(int j = 0; j < count[i]; j++){
            printf("%d, ", intervalBuffer[i][j]);
        }
    }
}