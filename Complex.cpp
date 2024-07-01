#include "Complex.hpp"

namespace std
{
    Complex::Complex(double re, double im)
        : _re(re), _im(im)
    {
    }

    bool Complex::operator!() const
    {
        return _re == 0 && _im == 0;
    }

    Complex Complex::operator-() const
    {
        return Complex(-_re, -_im);
    }

    double Complex::getRe() const
    {
        return _re;
    }

    double Complex::getIm() const
    {
        return _im;
    }

    bool operator==(const Complex &c1, const Complex &c2)
    {
        return c1.getRe() == c2.getRe() && c1.getIm() == c2.getIm();
    }

    ostream &operator<<(ostream &os, const Complex &complex)
    {
        os << complex.getRe() << " + " << complex.getIm() << "i";
        return os;
    }

    std::string to_string(const Complex &complex)
    {
        std::string str = std::to_string(complex.getRe()) + " + " + std::to_string(complex.getIm()) + "i";
        return str;
    }
}