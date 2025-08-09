#include<iostream>
using namespace std;
namespace myString {
   class clsString {
private:
    char* _data = nullptr ;
    int _len {0};
    int _capacity{0} ;
    int calculateLength(const char* str) {
        int len = 0;
        while (str[len] != '\0') len++;
        return len;
    }
    void * copyData (const char* data){
        for (int i = 0; i < _len; ++i){
            _data[i] = data[i];
        }
            _data[_len] = '\0';
    }
    void * copyToNewData (char* data){
        for (int i = 0; i < _len; ++i){
            data[i] = _data[i];
        }
            data[_len] = '\0';
    }

public:
    // constactor
    clsString(const char *data) ;
    clsString() ;
    clsString (const clsString& other);
    clsString& operator=(const clsString& other);
    // setter 
    void setData ( const char *data);
    // getter
    char* getData() ;
    //disconstator
    ~clsString() ;
    int length () ;
    int size ();
    bool empty () ;
    void clear ();
    char *cstr ();
    char *data ();
    int Capacity();
    void Reserve(int);
    void Shrink() ;
    void Resize(int) ;


};

}
