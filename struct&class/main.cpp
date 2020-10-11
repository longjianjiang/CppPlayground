//
//  main.cpp
//  struct&class
//
//  Created by longjianjiang on 2020/10/11.
//  Copyright © 2020 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

// C中的结构体一般用来包含不同数据类型的一个数据结构，支持嵌套；
// Cpp中的结构体和类很类似，支持继承，支持成员函数，支持多态；
// 选择的一个原则是，数据结构型使用结构体，对象型使用类。
struct SItem {
    int num;
};

struct ClassKindStructItem {
    int num;
    ClassKindStructItem(int num) {
        this->num = num;
    }
    /*
    virtual void show() {
        cout << "xxxx\n";
    }*/
};

class CItem {
public:
    int num;
    CItem(int num) {
        this->num = num;
    }
    /*
    virtual void show() {
        cout << "xxxx\n";
    }*/
};

void testAccessControl() {
    // 结构体支持 {} 形式进行初始化；
    SItem si = {5};
    cout << "si num = " << si.num << endl;
    
    // 类默认不支持，是因为类成员的默认访问控制不是public，改成public，一样支持 {} 初始化；
    CItem ci = {7};
    cout << "ci num = " << ci.num << endl;
    
    // 结构体或者类包含虚函数后，就不支持 {} 初始化；原因在于此时内存结构多了虚表；
    ClassKindStructItem cksi = {5};
}

// 结构体和类的另一个区别在于继承，结构体继承默认是public，类则是private；

int main(int argc, const char * argv[]) {

    return 0;
}
