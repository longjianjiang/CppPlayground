//
//  main.cpp
//  classPrivateStaticMember
//
//  Created by 蒋龙建 on 2020/5/20.
//  Copyright © 2020 longjianjiang. All rights reserved.
//

#include <iostream>

class Temp {
    public :
    Temp() {
        ++N;
        Sum += N;
    }
    
    static void Reset() {
        N = 0;
        Sum = 0;
    }
    
    static unsigned int GetSum() {
        return Sum;
    }
    
    private :
    static unsigned int N;
    static unsigned int Sum;
};

// 初始化类的静态非const需要在class body外面进行设置；(此时虽然是private但是依然可以访问到）
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
