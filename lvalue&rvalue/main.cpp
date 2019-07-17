//
//  main.cpp
//  lvalue&rvalue
//
//  Created by zl on 2019/7/17.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

void process_value(int& i) {
    cout << "lvalue is " << i << endl;
}

void process_value(int&& i) {
    cout << "rvalue is " << i << endl;
}

void forward_value(int&& i) {
    process_value(i);
}

class MyString {
private:
    char * _data;
    size_t _len;
    void _init_data(const char* s) {
        _data = new char[_len+1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
    void _clear_old() {
        if (_data) {
            free(_data);
        }
    }

public:
    MyString() {
        _data = nullptr;
        _len = 0;
    }

    MyString(const char* p) {
        _len = strlen(p);
        _init_data(p);
    }

    MyString(const MyString& str) {
        cout << "copy constructor is called! source: " << str._data << endl;
        _len = str._len;
        _init_data(str._data);
    }

    MyString(MyString&& str) { // 不能为const，因为需要修改str，这样不会因为右值析构后，转移到新对象的资源也无效了。
        cout << "move constructor is called! source: " << str._data << endl;
        _len = str._len;
        _data = str._data;
        str._len = 0;
        str._data = nullptr;
    }

    MyString& operator=(const MyString& str) {
        cout << "copy assignment is called! source: " << str._data << endl;
        if (this != &str) {
            _clear_old();
            _len = str._len;
            _init_data(str._data);
        }
        return *this;
    }

    MyString& operator=(MyString&& str) {
        cout << "move assignment is called! source: " << str._data << endl;
        if (this != &str) {
            _clear_old();
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = nullptr;
        }
        return *this;
    }

    ~MyString() {
        if (_data) {
            free(_data);
            _data = nullptr;
        }
    }
};

int main(int argc, const char * argv[]) {
    // 右值引用避免资源的重复创建
    MyString s;
    s = MyString("hello");

    // std::move 讲左值引用转成右值引用，达到减少拷贝的效果，std::swap内部实现就使用了std::move
    int num1 = 5, num2 = 7;
    swap(num1, num2);

    // perfect forwarding [ref](https://www.cnblogs.com/catch/p/3507883.html)
    forward<int>(num1);

    // 为什么b声明失败？
    /*
     int i = 0;
     const decltype((i)) b = 7;
     const int& a = 7;
     */

    return 0;
}
