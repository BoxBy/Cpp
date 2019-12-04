#include "ku_tfred.h"

int main(int argc, char* argv[2]){
    // argv[0] = number of threads
    // argv[1] = interval
    // argv[2] = input file

    FILE* file = fopen(argv[2], "r");
    int buffer[9999] = { 0 };

    for(int i = 0; i < 9999; i++)
        fscanf(file, "%d", &buffer[i]);

    int threadsNum = atoi(argv[0]);
    int interval = atoi(argv[1]);

}