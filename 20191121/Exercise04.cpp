#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

/*
int main(){
    queue<int> q;

    q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(11);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}

*/

int main(){
    const int howMany = 0;
    int i;
    priority_queue<int> nums;

    srand(time(0));
    for(i = 0; i < howMany; i++){
        int next = rand();
        cout << next << endl;
        nums.push(next);
    }
    cout << "\n*** Priority by value:" << endl;
    for(i = 0;i < howMany; i++){
        cout << nums.top() << endl;
        nums.pop();
    }

    return 0;
}