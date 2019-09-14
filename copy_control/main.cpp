//
//  main.cpp
//  copy_control
//
//  Created by longjianjiang on 2019/9/14.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

// 默认的拷贝构造和赋值操作符就是简单的按位复制，
// 一般当需要自定义析构函数的时候，说明需要处理动态分配的内存，此时需要自定义拷贝构造和赋值运算符。
// [ref](https://liam.page/2016/08/14/copy-control-in-Cpp/)

class Person {
public:
    int age;
    Person() {
        cout << "constructor be called\n";
        age = 10;
    }
    
    Person(const Person& p) {
        cout << "copy constructor be called\n";
        age = p.age;
    }
    
    Person& operator=(const Person& p) {
        cout << "operator= be called\n";
        if (this != &p) {
            age = p.age;
        }
        return *this;
    }
};


int main(int argc, const char * argv[]) {
    Person p;
    Person s = p; // call copy constructor
    s.age = 7;
    
    cout << p.age << endl;
    cout << s.age << endl;
    
    return 0;
}
