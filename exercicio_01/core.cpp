//
// Created by davim on 15/01/2022.
//
#include "core.h"
namespace core{
    void print_hello_word(){
        std::cout << "hello world!" << std::endl;
    }
    int fibonacci_01::fib(int n) {
        if (n<=1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
    int fibonacci_02::fib(int n) {
        int *f = new int(n+2);
        int i;
        f[0] = 0;
        f[1] = 1;
        for (i=2;i<=n;i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
}
