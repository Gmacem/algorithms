#pragma once

/*
If func(mid, args...) == true, then move left bound else right
limit - max number of check. Need for BinSearch<double>
*/

template<typename T, typename... ArgTypes>
T BinSearch(T left, T right, int limit, bool func(int, ArgTypes...), ArgTypes... args) {
    while (right - left > 1 && limit != 0) {
        T mid = (left + right) / 2;
        if (func(mid, args...)) {
            left = mid;
        } else {
            right = mid;
        }
        --limit;
    }
    return left;
}
