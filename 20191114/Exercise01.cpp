#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckIntArray{
private:
    int* arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr){}
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){}
public:
    BoundCheckIntArray(int len) : arrlen(len){
        arr = new int[len];
    }
    int& operator[](int idx){
        if(idx < 0 || idx > arrlen){
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[](int idx) const{
        if(idx < 0 || idx > arrlen){
            cout << "Array index out of bound exception" << endl;s
            exit(1);
        }
        return arr[idx];
    }
    int getArrlen() const { return arrlen; }
    ~BoundCheckIntArray(){ delete[] arr;}
};

void ShowAldata(const BoundCheckIntArray& ref){
    int len = ref.getArrlen();
    for(int idx = 0; idx < len; idx++)
        cout << ref[idx] << endl;
}

int main(){
    BoundCheckIntArray arr(5);
    for(int i = 0; i < 5; i++)
    arr[i] = (i+1)*11;
    ShowAldata(arr);
    return 0;
}