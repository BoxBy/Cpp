#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream ofs;
    ofs.open("exo2.txt");
    ofs.write("This is an apple", 16);

    long los = ofs.tellp();
    ofs.seekp(pos-7);
    ofs.write(" sam", 4);

    ofs.seekp(0, ios_base::end);
    char c = '!';
    ofs.put(c);
    ofs.close();
    
    return 0;
}