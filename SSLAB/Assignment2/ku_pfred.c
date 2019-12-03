#include "ku_pfred.h"

int main(int argc, char* argv[]){
    // argv[0] = number of processes
    // argv[1] = interval
    // argv[2] = input file

    FILE* file = fopen(argv[2], "r");
    int buffer[9999] = { 0 };

    for(int i = 0; i < 9999; i++)
        buffer[i] = fgetc(file);

    int processNum = atoi(argv[0]);
    int interval = atoi(argv[1]);

    
    
    
}