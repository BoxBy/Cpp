#include <iostream>
#include <string>

using namespeace std;

class BC1 { // base class 1
int x;
public:
    void set_x(float a) { x = a;}
};
class BC2 { // base class 2
int x;
public:
void set_x(char a) { x = a; }
};
class DC : public BC1, public BC2 {
int x;
public:
void set_x(int a) { x = a; }
};
void tester(){
    DC d1;
    //DC::set_x
    d1.set_x(137);
    //Error: DC::set_x hides // set_x of BC1 and BC2 d1.set_x(1.23); d1.set_x('c');
    //BC1::set_x
    d1.BC1::set_x(1.23);
    //BC2::set_x
    d1.BC2::set_x('c');
};
int main(){
    tester();
    return 0;
}