//
//  main.cpp
//  offsetof
//
//  Created by zl on 2019/8/23.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

// offsetof 宏用来计算结构体成员之间的偏移
#define my_offsetof(type, member) ((size_t)&((type *)0)->member)

struct AA {
    int a;
    int b;
    int c;
};

int main(int argc, const char * argv[]) {
    cout << my_offsetof(AA, a) << endl;
    cout << my_offsetof(AA, b) << endl;
    cout << my_offsetof(AA, c) << endl;

    AA *pa = new AA();
    pa->a = 7;
    pa->b = 2;
    pa->c = 5;

    // pa 不转成char *, ++ 移动距离的是sizeof(AA)
    char *pp = (char *)pa;
    int *a = (int *)pp;
    int *b = (int *)(pp+4);
    int *c = (int *)(pp+8);

    cout << *a << endl;
    cout << *b << endl;
    cout << *c << endl;

    return 0;
}
