//
//  main.cpp
//  flexibleArrayMember
//
//  Created by zl on 2019/8/9.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

// 柔性数组历史
typedef struct Person {
    int len;
    char *name;
} Person;

void test() {
    char name[] = "nancy";

    // Person内存有两部分，一部分是结构体，另一部分则是name，
    // 所以首先定位到存储name的首地址进行strcpy，之后更新p->name的指向。
    Person *p = (Person *)malloc(sizeof(Person) + sizeof(name));
    p->len = (int)strlen(name);
    strcpy((char *)&p->name+sizeof(p->name), name);
    p->name = (char *)&p->name + sizeof(p->name); // 更新name

    cout << p->len << endl;
    cout << p->name << endl;
}

// 网络编程中柔性数组是不可缺少的，因为事先是不知道data size的
typedef struct F_Person {
    int len;
    char name[0];
} F_Person;

void test_flexible() {
    char name[] = "nancy";
    
    // name[0] 的形式是👆一样的道理, name[0]是不占空间的。
    F_Person *p = (F_Person *)malloc(sizeof(F_Person) + sizeof(name));
    p->len = (int)strlen(name);
    strcpy((char *)(p+4), name);
    strcpy(p->name, "jiang"); // 也可以直接使用p->name

    cout << p->len << endl;
    cout << p->name << endl;
}

int main(int argc, const char * argv[]) {
    test();
    cout << endl;
    test_flexible();

    return 0;
}
