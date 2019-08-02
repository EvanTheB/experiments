#include <iostream>

struct X {
    int i{2};

    X() {
        std::cout << "default constructor called" << std::endl;
    }

    X(const X& other) {
        std::cout << "copy constructor called" << std::endl;
    }
    
    X(X&&) = default; 
};

X createX() {
    X x;
    std::cout << "created x on the stack" << std::endl;
    return x;
}

int main() {
    X x1;
    std::cout << "created x1" << std::endl;
    std::cout << "x1: " << x1.i << std::endl << std::endl;    

    X x2 = createX();
    std::cout << "created x2" << std::endl;
    std::cout << "x2: " << x2.i << std::endl;    

    return 0;
}
