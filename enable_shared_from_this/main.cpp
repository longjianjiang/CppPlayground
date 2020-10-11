//
//  main.cpp
//  enable_shared_from_this
//
//  Created by 蒋龙建 on 2020/3/26.
//  Copyright © 2020 longjianjiang. All rights reserved.
//

#include <iostream>
#include <memory>

class Bad {
public:
    mutable std::weak_ptr<Bad> __weak_this_;
    std::shared_ptr<Bad> getPtr() {
        return std::shared_ptr<Bad>(__weak_this_);
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad deinit be called;\n"; }
};

class Good: public std::enable_shared_from_this<Good> {
public:
    std::shared_ptr<Good> getPtr() {
        return shared_from_this();
    }
    ~Good() { std::cout << "Good deinit be called;\n"; }
};

// 当某个类中需要将this传递到其他函数，此时不能直接使用this去构建一个`shared_ptr`，这样做会导致两个独立的指针指向同一块内存，deinit两次；
// 这个时候`enable_shared_from_this`这个基类提供了一个返回shared_ptr的方法；
// 需要使用的场景一般是在异步调用中，为了保证异步回调中可以正常使用外部的变量，需要有一个shared_ptr指向外部变量，这样外部变量可以一直存活；

// [ref](http://blog.guorongfei.com/2017/01/25/enbale-shared-from-this-implementaion/)

int main(int argc, const char * argv[]) {
    std::shared_ptr<Bad> pBadOne(new Bad());
    std::shared_ptr<Bad> pBadTwo = pBadOne->getPtr();
    std::cout << "pBadOne use_count = " << pBadOne.use_count() << std::endl;
    std::cout << "pBadTwo use_count = " << pBadTwo.use_count() << std::endl;
    
    std::shared_ptr<Good> pGoodOne(new Good());
    std::shared_ptr<Good> pGoodTwo = pGoodOne->getPtr();
    std::cout << "pGoodOne use_count = " << pGoodOne.use_count() << std::endl;
    std::cout << "pGoodTwo use_count = " << pGoodTwo.use_count() << std::endl;
    
    return 0;
}
