/**
 * ------------------------------------------------------------------------
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
 * see that the 6th prime is 13.
 *
 * What is the 10,001st prime number?
 * ------------------------------------------------------------------------
 * I know from...somewhere that prime numbers can be calculated using the
 * formula
 *     p = 6k +- 1
 * for all primes greater than 2.  It's not entirely reliable, but it definitely
 * cuts down on the number of checks we need to do.
 */
 
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>

std::vector<unsigned long> foundPrimes;

bool isPrime(unsigned int x) {
    if (x <= 3) {
        return true;
    }
    
    if (x % 2 == 0) {
        return false;
    }
    
    int root = sqrt(x) + 0.5;
    for (unsigned int i = 3; i <= root; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    
    return true;
}

unsigned int findNthPrime(unsigned int n) {
    unsigned int count = 3;
    unsigned int ret = 0;
    for (unsigned int i = 1; count < n; i++) {
        unsigned int low = 6 * i - 1;
        unsigned int high = 6 * i + 1;
        
        if (isPrime(low)) {
            count++;
            if (count < n) {
                ret = low;
            }
        }
        
        if (isPrime(high)) {
            count++;
            if (count < n) {
                ret = high;
            }
        }
    }
    
    return ret;
}

int main() {
    clock_t t;
    unsigned int answer;
    float avgTime;
    
    t = clock();
    for (int i = 0; i < 100; i++) {
        answer = findNthPrime(10001);
    }
    t = clock() - t;
    
    avgTime = t / 100.f;
    
    std::cout << "Answer: " << answer << std::endl
              << "Time: " << avgTime << "ms" << std::endl;
    
    return 0;
}