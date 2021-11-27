#include <iostream>


int main()
{
    typedef int my_int;
    my_int tick = 100;
    std::cout << "my_int tick is " << tick << "\n";

    enum color : uint16_t{
        green,
        blue,
        red
    };
    color a = green;
    color b = blue;
    std::cout << "a is type " << typeid(a).name() << "\n";
    std::cout << "color of a is " << a << ", b is " << b << "\n";
    std::cout << "a is 0 : " << (a == 0) << "\n";
}