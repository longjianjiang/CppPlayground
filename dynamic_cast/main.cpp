//
//  main.cpp
//  dynamic_cast
//
//  Created by zl on 2019/8/15.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>

// dynamic_cast 用在多态类型的转换，所谓多态类型就是某个类public继承其他类或者m拥有虚函数(继承或者自定义)

// reinterpret_cast 大概意思是将当前变量的内存存储的二进制进行换一种类型进行表达

class Shape {
public:
    virtual void draw() {}
};

class Rollable {
public:
    virtual void roll() {}
};

class Square : public Shape {
public:
    void draw() {
        std::cout << "draw square\n";
    }
};

class Circle : public Shape, public Rollable {
public:
    void draw() {
        std::cout << "draw circle\n";
    }

    void roll() {
        std::cout << "roll circle\n";
    }
};

void test_dc() {
    // Down cast
    Shape *shape = new Shape();
    Square *s1 = dynamic_cast<Square *>(shape); // 转换失败，s1为NULL

    // Cross cast
    shape = new Square();
    Rollable *r1 = dynamic_cast<Rollable *>(shape); // 转换失败, r1为NULL

    shape = new Circle();
    Rollable *r2 = dynamic_cast<Rollable *>(shape); // 转换成功
}

void test_rc() {
    int i = 0x63006261; // 'a' ASCII 十六进制是61
    int *pi = &i;
    char *s = reinterpret_cast<char *>(pi); // "ab"

    std::cout << std::hex << i << "\n";
    std::cout << s << "\n";
}

int main(int argc, const char * argv[]) {
    test_rc();
    return 0;
}

// https://www.cnblogs.com/weidagang2046/archive/2010/04/10/1709226.html
