#include "ku_pfred.h"
// 주석은 전부 processNum이 5일때를 가정하고 적음

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
    // forkNum이 0, 1, 2, 3, 4인 프로세스가 생긴다

    int intervalBuffer[20][9999] = { 0 };
    int count[20] = { 0 };

    while(forkNum <= 9999){
        for(int process = 0; process < processNum; process++){ //프로세스 할당
            if(process == forkNum % processNum){ // forkNum의 값이 변하므로 processNum으로 나눈 나머지를 비교해야 한다 
                for(int pointer = 1; pointer <= interval; pointer++){
                    if((int)(buffer[forkNum] / interval) == pointer){ // 몇번째 interval인지 확인후 넣어준다
                        intervalBuffer[pointer][count[pointer]] = buffer[forkNum];
                        count[pointer]++;
                    }
                }
            }
        forkNum += 5;
        }
    }

    forkNum %= 5; // forkNum 복구

    for(int i = 0; i < 9999; i++) // 이젠 필요없으니 다른값을 저장하기 위하여 Buffer를 비워준다
        buffer[i] = 0;

    for(int i = 1; i <processNum; i++){ // forkNum이 0이라면 부모 프로세스이므로 제외한다
        if(forkNum == i){
            mq_send(mfd, intervalBuffer, count, forkNum);    //messagequeue로 보낸다
        }
        if(forkNum == 0){
            waitpid(pid[i], NULL, 0);
            mq_receive(mfd, buffer, countTemp, NULL);   //forkNum이 0인 부모 프로세스에 값을 모아준다
            for(int j = 0; j < 20; j++){
                *intervalBuffer[i] = addArr(intervalBuffer[i], count[i], buffer, countTemp);
                count[i] += countTemp;
            }
        }
    }

    for(int i = 4; i > 0; i++) // 프로세스 종료
        if(forkNum == i)
            exit(0);
    
    for(int i = 0; i < interval; i++)
        qsort(intervalBuffer[i], count[i], sizeof(int), compare); // 정렬

    countTemp = 0;

    for(int i = 0; i < interval; i++){ // 출력
        printf("%d ~ %d = ", countTemp, countTemp + (int)(9999 / interval));
        for(int j = 0; j < count[i]; j++){ // 개수도 알려줘야됨
            printf("%d, ", intervalBuffer[i][j]);
        }
    }


    return 0;
}