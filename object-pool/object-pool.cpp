#include <iostream>
#include <vector>
#include <memory>

class MyObject {
public:
    MyObject() { std::cout << "Object created." << std::endl; }
    ~MyObject() { std::cout << "Object destroyed." << std::endl; }

    void doSomething() {
        std::cout << "Object doing something." << std::endl;
    }
};

class ObjectPool {
private:
    std::vector<std::unique_ptr<MyObject>> pool;

public:
    ObjectPool(int initialSize) {
        for (int i = 0; i < initialSize; ++i) {
            pool.push_back(std::make_unique<MyObject>());
        }
    }

    std::unique_ptr<MyObject> acquireObject() {
        if (!pool.empty()) {
            std::unique_ptr<MyObject> obj = std::move(pool.back());
            pool.pop_back();
            return obj;
        } else {
            return std::make_unique<MyObject>();
        }
    }

    void releaseObject(std::unique_ptr<MyObject> obj) {
        pool.push_back(std::move(obj));
    }
};

int main() {
    ObjectPool pool(3);

    // 获取并使用对象
    std::unique_ptr<MyObject> obj1 = pool.acquireObject();
    obj1->doSomething();

    std::unique_ptr<MyObject> obj2 = pool.acquireObject();
    obj2->doSomething();

    // 释放对象
    pool.releaseObject(std::move(obj1));
    pool.releaseObject(std::move(obj2));

    return 0;
}