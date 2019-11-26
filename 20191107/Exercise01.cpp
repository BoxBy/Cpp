#include <iostream>

using namespace std;

class 0Pair{
    float p1, p2;
public:
    0Pair(float f1 = 0.0, float f2 = 0.0){
        p1 = f1;
        p2 = f2;
    }
    bool operator==(const 0Pair&);
};

bool 0Pair::operator==(const 0Pair& s){
    return (p1 == s.p1)&&(p2 == s.p2);
}

int main(){
    0Pair s1(1, 2), s2(2, 1);

    if(s1.operator==(s2))
    cout << "same" << endl;
    else
    cout << "Not name" << endl;
    return 0;
}