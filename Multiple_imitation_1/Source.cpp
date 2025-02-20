#include <iostream>

template <typename T1, typename T2>
class base {
protected:
    T1 value1;
    T2 value2;

public:
    base(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    void show() const {
        std::cout << "Base values: " << value1 << ", " << value2 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class child : public base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    child(T1 v1, T2 v2, T3 v3, T4 v4) : base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    void show() const {
        base<T1, T2>::show();
        std::cout << "Child values: " << value3 << ", " << value4 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class child2 : public child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    void show() const {
        child<T1, T2, T3, T4>::show();
        std::cout << "Child2 values: " << value5 << ", " << value6 << std::endl;
    }
};

int main() {
    base<int, double> b(10, 20.5);
    b.show();

    child<int, double, char, std::string> c(1, 2.5, 'A', "Hello");
    c.show();

    child2<int, double, char, std::string, bool, float> c2(1, 2.5, 'B', "World", true, 3.14f);
    c2.show();

    return 0;
}
