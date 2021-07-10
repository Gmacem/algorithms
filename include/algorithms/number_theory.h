#pragma once
#include <assert.h>
#include <string>
#include <sstream>
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

template<class T>
T GCD(T a, T b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<class T>
T Abs(T val) {
    if (val < 0) {
        return -val;
    }
    if (val > 0) {
        return val;
    }
    return 0;
}

template<class T>
T Sign(T val) {
    if (val < 0) {
        return -1;
    }
    if (val > 0) {
        return 1;
    }
    return 0;
}

/*
 * TODO +=, -=, *=, /=
 * 
 * 
 * 
 * 
 */

template<class T>
class Fraction {
public:
    Fraction(): numerator_(0), denominator_(1), normalize_(true) {
    }

    Fraction(T a, T b, bool norm=true): numerator_(a), denominator_(b), normalize_(norm) {
        assert(b != 0);
        normalize();
    }

    Fraction operator+(const Fraction& other) const  {
        return Fraction(numerator_ * other.denominator_ + denominator_ * other.numerator_,
                        denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator_ * other.denominator_ + denominator_ * other.numerator_,
                        denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator*(T val) const {
        return Fraction(numerator_ * val, denominator_);
    }

    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    T Numerator() const {
        return numerator_;
    }

    T Denominator() const {
        return denominator_;
    }
    
    std::string GetString() {
        std::ostringstream stringStream;
        stringStream << numerator_ << "/" << denominator_ << '\n';
        return stringStream.str();
    }

private:
    void normalize() {
        if (!normalize_) {
            return;
        }
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
        T g = GCD(Abs(a), Abs(b));
        a /= g;
        b /= g;
        numerator_ = a;
        denominator_ = b;
    }
    
private:
    T numerator_, denominator_;
    bool normalize_;
};
