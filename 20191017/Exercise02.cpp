#include <iostream>
#include <string>

using namespace std;

class Animal{
    string species;
    public:
    Animal(){ species = "Animal";}
    Animal(const char* s){species = s;}
};

class Primate : public Animal{
    public:
    Primate() : Animal("Primate"){}
    Primate(int n) : Animal("Primate"){
        heart_cham = n;
    }
    private:
    int heart_cham;
};

int main(){
    Animal slug;
    Animal tweety("canary");
    Primate godzilla;
    Primate human(4);
}