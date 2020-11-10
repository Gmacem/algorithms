#pragma once
#include <vector>

template<class T>
bool IsPrimeSimple(T num) {
    if (num == 1) {
        return false;
    }
    for (T i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

template<class T>
std::vector<T> Factorize(T num, T bound) {
    std::vector<T> ans;
    for (T i = 2; i < bound && i < num; ++i) {
        while (num % i == 0) {
            ans.emplace_back(i);
            num /= i;
        }
    }
    if (num != 1) {
        ans.emplace_back(num);
    }
    return ans;
}
