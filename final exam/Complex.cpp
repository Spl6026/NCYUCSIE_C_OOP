#include <iostream>

using namespace std;

class Complex {
    int real, image;

    friend istream &operator>>(istream &is, Complex &C) {
        is >> C.real >> C.image;
        return is;
    }

    friend ostream &operator<<(ostream &os, Complex C) {
        if (C.image >= 0)
            os << C.real << '+' << C.image << 'i';
        else
            os << C.real << C.image << 'i';
        return os;
    }

public:
    Complex() {}

    Complex(int r, int i) : real(r), image(i) {}

    Complex operator+(Complex &C) const {
        return Complex(real + C.real, image + C.image);
    }

    Complex operator-(Complex &C) const {
        return Complex(real - C.real, image - C.image);
    }

    Complex operator*(Complex &C) const {
        return Complex((real * C.real) - (image * C.image), (real * C.image) + (image * C.real));
    }

    Complex operator/(Complex &C) const {
        return Complex(
                (real * C.real + image * C.image) / (C.real * C.real + C.image * C.image),
                (image * C.real - real * C.image) / (C.real * C.real + C.image * C.image));
    }
};

int main() {

    Complex c1, c2;
    char op;
    while (cin >> c1 >> op >> c2) {
        switch (op) {
            case '+':
                cout << c1 + c2 << endl;
                break;
            case '-':
                cout << c1 - c2 << endl;
                break;
            case '*':
                cout << c1 * c2 << endl;
                break;
            case '/':
                cout << c1 / c2 << endl;
                break;
        }
    }
}
