/*
* The sum of the squares of the first ten natural numbers is,
*   1^2 + 2^2 + ... + 10^2 = 385
* The square of the sum of the first ten natural numbers is,
*   (1 + 2 + ... + 10)^2 = 55^2 = 3025
* Hence the difference between the sum of the squares of the first ten natural
* numbers and the square of the sum is 3025 - 385 = 2640.
* 
* Find the difference between the sum of the squares of the first one hundred
* natural numbers and the square of the sum.
*/

#include <iostream>
#include <cassert>

#define UPPER 100

int sigmaSquared(int upper) {
    int sum = 0;
    for (int i = 1; i <= upper; i++) {
        sum += i;
    }
    
    return sum * sum;
}

int squaredSigma(int upper) {
    int sum = 0;
    for (int i = 1; i <= upper; i++) {
        sum += i*i;
    }
    
    return sum;
}

namespace soln {

int sigmaSquared(int upper) {
    int sum = upper * (upper + 1) / 2;
    return sum * sum;
}

int squaredSigma(int upper) {
    return (((2 * upper) + 1) * (upper + 1) * upper) / 6;
}

}

int main() {
    int myAnswer = sigmaSquared(100) - squaredSigma(100);
    int answer = soln::sigmaSquared(100) - soln::squaredSigma(100);
    
    std::cout << "My solution: " << myAnswer << std::endl;
    std::cout << "Given solution: " << answer << std::endl;
    
    return 0;
}
