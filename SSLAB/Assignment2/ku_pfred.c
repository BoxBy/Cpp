#include "ku_pfred.h"
// �ּ��� ���� processNum�� 5�϶��� �����ϰ� ����

int main(int argc, char* argv[3]){
    // argv[0] = number of processes
    // argv[1] = interval
    // argv[2] = input file

    FILE* file = fopen(argv[2], "r");
    int buffer[9999] = { 0 };

    for(int i = 0; i < 9999; i++)
        fscanf(file, "%d", &buffer[i]);

    fclose(file);

    int processNum = atoi(argv[0]);
    int interval = atoi(argv[1]);
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

    int intervalBuffer[20][9999] = { 0 };
    int count[20] = { 0 };

    while(forkNum <= 9999){
        for(int process = 0; process < processNum; process++){ //���μ��� �Ҵ�
            if(process == forkNum % processNum){ // forkNum�� ���� ���ϹǷ� processNum���� ���� �������� ���ؾ� �Ѵ� 
                for(int pointer = 1; pointer <= interval; pointer++){
                    if((int)(buffer[forkNum] / interval) == pointer){ // ���° interval���� Ȯ���� �־��ش�
                        intervalBuffer[pointer][count[pointer]] = buffer[forkNum];
                        count[pointer]++;
                    }
                }
            }
        forkNum += 5;
        }
    }

    forkNum %= 5; // forkNum ����

    for(int i = 0; i < 9999; i++) // ���� �ʿ������ �ٸ����� �����ϱ� ���Ͽ� Buffer�� ����ش�
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
        qsort(intervalBuffer[i], count[i], sizeof(int), compare); // ����

    countTemp = 0;

    for(int i = 0; i < interval; i++){ // ���
        printf("%d ~ %d = ", countTemp, countTemp + (int)(9999 / interval));
        for(int j = 0; j < count[i]; j++){ // ������ �˷���ߵ�
            printf("%d, ", intervalBuffer[i][j]);
        }
    }


    return 0;
}