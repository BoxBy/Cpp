#include "ku_pfred.h"
#define BUFFER_SIZE 10000
// �ּ��� ���� processNum�� 5�϶��� �����ϰ� ����

int main(int argc, char* argv[3]){
    // argv[1] = number of processes
    // argv[2] = interval
    // argv[3] = input file

    FILE* file = fopen(argv[3], "r");
    int buffer[BUFFER_SIZE] = { 0 };

    for(int i = 0; i < BUFFER_SIZE; i++)
        fscanf(file, "%d", &buffer[i]);

    fclose(file);

    int processNum = atoi(argv[1]);
    int interval = atoi(argv[2]);
    int forkNum = 0;
    int countTemp = 0;

    pid_t pid[processNum];
    mqd_t mfd = mq_open("/my_mq", O_WRONLY);

    if(mfd == -1){
        perror("open error");
        exit(0);
    }

    for(int i = 0; i < processNum; i++){
        if(pid[processNum] = fork())
            break;
        forkNum++;
    }
    // forkNum�� 0, 1, 2, 3, 4�� ���μ����� �����

    int intervalBuffer[20][BUFFER_SIZE] = { 0 };
    int count[20] = { 0 };

    while(forkNum <= BUFFER_SIZE){
        for(int process = 0; process < processNum; process++){ //���μ��� �Ҵ�
            if(process == forkNum % processNum){ // forkNum�� ���� ���ϹǷ� processNum���� ���� �������� ���ؾ� �Ѵ� 
                for(int pointer = 1; pointer <= interval; pointer++){
                    if((int)(buffer[forkNum] / interval) == pointer){ // ���° interval���� Ȯ���� �־��ش�
                        intervalBuffer[pointer][count[pointer]] = buffer[forkNum];
                        count[pointer]++;
                    }
                }
            }
        forkNum += processNum;
        }
    }

    forkNum %= 5; // forkNum ����

    for(int i = 0; i < BUFFER_SIZE; i++) // ���� �ʿ������ �ٸ����� �����ϱ� ���Ͽ� Buffer�� ����ش�
        buffer[i] = 0;

    for(int i = 1; i <processNum; i++){ // forkNum�� 0�̶�� �θ� ���μ����̹Ƿ� �����Ѵ�
        if(forkNum == i){
            mq_send(mfd, intervalBuffer, count, forkNum);    //messagequeue�� ������
        }

        if(forkNum == 0){
            waitpid(pid[i], NULL, 0);
            mq_receive(mfd, buffer, countTemp, NULL);   //forkNum�� 0�� �θ� ���μ����� ���� ����ش�
            for(int j = 0; j < 20; j++){
                *intervalBuffer[i] = addArr(intervalBuffer[i], count[i], buffer, countTemp);
                count[i] += countTemp;
            }
        }

    }

    for(int i = 4; i > 0; i++) // ���μ��� ����
        if(forkNum == i)
            exit(0);
    
    for(int i = 0; i < interval; i++)
        qsort(intervalBuffer[i], count[i], sizeof(int), compare); // sorting

    countTemp = 0;

    for(int i = 0; i < interval; i++){ // print
        printf("%d ~ %d = ", countTemp, countTemp + (int)(BUFFER_SIZE / interval));
        for(int j = 0; j < count[i]; j++){
            printf("%d, ", intervalBuffer[i][j]);
        }
        puts("");
    }


    return 0;
}