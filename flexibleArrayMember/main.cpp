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
