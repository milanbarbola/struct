#include<iostream>
template<typename T>
struct Vector2
{
    T x,y;

    Vector2<T>() = default;
    Vector2<T>(T x_, T y_) : x(x_), y(y_) {}

    Vector2<T>& operator+=( Vector2<T> const& v)
    {
        x += v.x; y += v.y; 
        return *this;
    }
    Vector2<T>& operator-=( Vector2<T> const& v)
    {
        x -= v.x; y -= v.y;
        return *this;
    }
    Vector2<T>& operator*=( T scal)
    {
        x *= scal; y *= scal;
        return *this;
    }
    Vector2<T>& operator/=( T scal)
    {
        x /= scal; y /= scal;
        return *this;
    }
};

template<typename T>
Vector2<T> operator+(Vector2<T> const& a, Vector2<T> const& b)
{
    return Vector2<T>{a.x + b.x, a.y + b.y};
}
template<typename T>
Vector2<T> operator-(Vector2<T> const& a, Vector2<T> const& b)
{
    return Vector2<T>{a.x - b.x, a.y - b.y};
}
template<typename T>
Vector2<T> operator*(Vector2<T> const& a,T scal)
{
    return Vector2<T>(a.x * scal, a.y * scal);
}
template<typename T>
Vector2<T> operator/(Vector2<T> const& a, T scal)
{
    return Vector2<T>(a.x / scal, a.y / scal);
}


int main(){

    Vector2<double> v = {1.0,2.0};
    Vector2<double> u = {4.0, -2.0};
    auto w_sum = v + u;
    auto w_sub = v - u;
    auto w_mult = v*2.0;
    auto w_div = v/2.0;
    std::cout<<"Sum with the + operator: "<< w_sum.x << " " << w_sum.y << "\n";
    std::cout<<"Substruction with the - operator: "<< w_sub.x << " " << w_sub.y << "\n";
    std::cout<<"Multiplication with the * operator: "<< w_mult.x << " " << w_mult.y << "\n";
    std::cout<<"Dividing with the / operator: "<< w_div.x << " " << w_div.y << "\n";
    std::cout << "\n";
    auto w_sum1 = v += u;
    auto w_sub1 = v -= u;
    auto w_mult1 = v*2.0;
    auto w_div1 = v/2.0;
    std::cout<<"Sum with the += operator: "<< w_sum1.x << " " << w_sum1.y << "\n";
    std::cout<<"Substruction with the -= operator: "<< w_sub1.x << " " << w_sub1.y << "\n";
    std::cout<<"Multiplication with the *= operator: "<< w_mult1.x << " " << w_mult1.y << "\n";
    std::cout<<"Dividing with the /= operator: "<< w_div1.x << " " << w_div1.y << "\n";
    return 0;
}