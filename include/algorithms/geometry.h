#pragma once

template<class T>
class Point {
public:
    Point();
    Point(T x, T y);
    
private:
    T x_, y_;
};
