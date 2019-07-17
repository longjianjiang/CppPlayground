//
//  main.cpp
//  decltype
//
//  Created by zl on 2019/7/17.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 decltype 用来进行给定表达式的类型推导，规则如下:
 1> exp是标识符，返回标识符的类型;
 2> exp是函数调用，返回函数返回值的类型;
 3> 其他情况，当exp的结果类型可以作为左值，则返回对应类型的引用类型; 例如解引用操作。
 */

int main(int argc, const char * argv[]) {
    int i = 42, *p = &i, &r = i;

    decltype(i) a; // int
    decltype(r + 0) b; // r+0 => int
    decltype(*p) c; // int&, 必须初始化

    return 0;
}
