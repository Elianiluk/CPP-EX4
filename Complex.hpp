#pragma once

#include <iostream>
#include <vector>
#include <string>

/*author: elian iluk
email: elian10119@gmail.com
id:214787483
*/


namespace std{
    class Complex
    {
    public:
        Complex(double re, double im);
        bool operator!() const;
        Complex operator-() const;
        double getRe() const;
        double getIm() const;
        friend ostream &operator<<(ostream &os, const Complex &complex);
        friend bool operator==(const Complex& c1, const Complex& c2);
        friend std::string to_string(const Complex &complex);
        friend bool operator<(const Complex &c1, const Complex &c2);

    private:
        double _re;
        double _im;
    };
}