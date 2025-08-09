#include"../header/clsString.h"
namespace myString {
    // constactor
    clsString::clsString(const char* data) {
        // measure the length manually.
        _len = calculateLength(data) ;
        _capacity = _len+ (_len*2);
        // use heap to seize memory
        _data = new char[_capacity + 1];


        // copy charcter one by one
        copyData(data) ;
    }
    clsString::clsString() {
        _len = calculateLength(_data) ;
        _capacity= _len + (_len*2);
        _data = new char[1];
        _data[0] = '\0';
        }
    clsString::clsString(const clsString& other) {
    _len = other._len;
    _capacity = other._capacity;
    _data = new char[_capacity + 1];

    for (int i = 0; i <= _len; ++i)  // include '\0'
        _data[i] = other._data[i];
}
    clsString& clsString::operator=(const clsString& other) {
    if (this != &other) {  // حماية من self-assignment
        delete[] _data;

        _len = other._len;
        _capacity = other._capacity;
        _data = new char[_capacity + 1];

        for (int i = 0; i <= _len; ++i)
            _data[i] = other._data[i];
    }

    return *this;
}


    // setter 
    void clsString::setData ( const char *data){
        if (data == nullptr) return;  // إضافة هذا
        delete[] _data;
        // measure the length manually.
            _len = calculateLength(data) ;

            // use heap to seize memory
            _capacity = _len + (_len*2);
            _data = new char[_capacity + 1];

            // copy charcter one by one
            copyData(data);
            }

    // getter
    char* clsString::getData() {
        return _data;
    }
    //disconstator
    clsString::~clsString() {
        delete[] _data;
    }
   
    int clsString::length(){
        return _len ;
    }

    int clsString::size(){
        return this->length();
    }
    bool clsString::empty(){
        if (this->length() == 0){
            return true ;
        }
        return false ;
    }
   
  void clsString::clear() {
        _len = 0;
        if (_data) {
            _data[0] = '\0';
        }
    }

    char * clsString::cstr(){
        return _data ;
    }
    char * clsString::data(){
        return &_data[0];
    }
    int clsString::Capacity(){
        return _capacity ;
    }

   void clsString::Reserve(int num) {
    if (num <= _capacity)
        return; 

    // حجز مساحة جديدة
    char* newChar = new char[num + 1];

    // نقل البيانات
    copyToNewData(newChar);

    // حذف القديم
    delete[] _data;

    // تحديث المؤشرات والقيم
    _data = newChar;
    _capacity = num;
}
   void clsString::Shrink(){
    _capacity = _len ;
    char* newChar = new char [_capacity +1 ];

    // loop to copy old pointer
    copyToNewData(newChar);

    delete[] _data ;
    _data = newChar ;
   } 
   void clsString::Resize(int num ){
    if (num < _len){
        _data[num] ='\0'; 
        
    }
    else if (num > _len){
        if (num > _capacity)
            Reserve(num);
        for (int i  = _len ; i < num ; i++){
            _data[i] =' ';
        }
        _data[num] = '\0';
       
    }
     _len = num ;
   }
}
