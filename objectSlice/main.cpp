//
//  main.cpp
//  objectSlice
//
//  Created by 蒋龙建 on 2020/3/20.
//  Copyright © 2020 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

class Base {
public:
    virtual void func() {
        cout << "Base call func;\n";
    }
};

class Derived : public Base {
public:
    virtual void func() {
        cout << "Derived call func;\n";
    }
};

void func_1(Base b) {
    b.func();
}

void func_2(Base *b) {
    b->func();
}

void func_3(Base &b) {
    b.func();
}

int main(int argc, const char * argv[]) {
    Derived d;
    
    // 编译期间，产生对象切割，将子类对象赋值给父类，此时编译器就会认为赋值后的对象就是父类；
    func_1(d);
    
    // 多态，此时父类对象指向的内存是子类；
    func_2(&d);
    func_3(d);
    
    return 0;
}
