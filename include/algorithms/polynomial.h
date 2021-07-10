#pragma once
#include <vector>


template<class TValue>
class Polynomial {
public:
    Polynomial() {
        _values.push_back(0);
    }
    
    size_t Size() {
        return _values.size();
    }

private:
    std::vector<TValue> _values;
};


template<class TValue>
Polynomial<TValue> FFT(const Polynomial<TValue>& lhs, const Polynomial<TValue>& rhs) {
    
}
