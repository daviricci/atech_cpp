#include "core.h"
int main() {
    core::print_hello_word();
    core::fibonacci_01 f1;
    core::fibonacci_02 f2;
    std::cout<< f1.fib(6) << std::endl;
    std::cout<< f2.fib(6) << std::endl;
    return 0;
}
