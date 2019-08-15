//
//  main.cpp
//  any&variant
//
//  Created by zl on 2019/8/15.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <any>
#include <variant>

struct VOutput {
    template <typename T>
    void operator()(const T& val) {
        std::cout << val << std::endl;
    }

    void operator()(const std::string& str) {
        std::cout << "item is " << str << std::endl;
    }
};

void test_variant() {
    // 类似union
    std::variant<int, float, std::string> v;
    try {
        int num = std::get<int>(v);
    } catch (std::bad_variant_access e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<decltype(v)> list;
    list.push_back(5);
    list.push_back("nancy");

    auto visitor = VOutput();
    for (auto item : list) {
        // 使用visitor实现定义好所有可能的类型，用std::visit进行调用
        // 1. 自定义对象，当需要最某个类型单独处理；
        /* std::visit(visitor, item); */

        // 2. 使用generic lambda；
        std::visit(
                   [](const auto& v) { std::cout << v << std::endl;},
                   item);
    }
}

void test_any() {
    // 类似类型安全的void*
    std::any a = 1;
    std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
    try {
        std::cout << std::any_cast<float>(a) << '\n';
    }
    catch (const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }

    // 指向所含数据的指针
    int* i = std::any_cast<int>(&a);
    std::cout << *i << "\n";
}

int main(int argc, const char * argv[]) {
    test_variant();

    test_any();
    return 0;
}

// https://kheresy.wordpress.com/2017/10/16/cpp17-variant/
