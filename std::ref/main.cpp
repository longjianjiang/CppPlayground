//
//  main.cpp
//  std::ref
//
//  Created by zl on 2019/7/20.
//  Copyright © 2019 longjianjiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

class Foo {
    mutex m;

public:
    Foo() = default;
};

void t1(Foo& f) {

}

void mutexRelated() {
    Foo f;
    
    // 因为传递到线程入口函数的参数默认是copy到线程栈中，mutex不能copy，所以需要进行传递引用，
    // 函数参数为引用，传递的参数通过ref()来构造一个引用。
    thread first (t1, ref(f));
    first.join();
}

void collectionRelated() {
    vector<vector<int>> list(1, vector<int>());
    
    vector<int> child = list[0];
    vector<int>& child_ref = ref(list[0]);
    
    child.push_back(7);
    // list中存的子数组并不是引用，所以如果想要直接修改list，需要拿到子数组的引用进行操作。
    child_ref.push_back(7);
}

int main(int argc, const char * argv[]) {
    return 0;
}
