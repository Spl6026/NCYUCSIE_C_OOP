#include <iostream>
#include <vector>

using namespace std;

class Matrix {

    int r, c;

    friend istream &operator>>(istream &is, Matrix &m) {
        is >> m.r >> m.c;
        m.v.clear();
        for (int i = 0; i < m.r * m.c; i++) {
            int t;
            is >> t;
            m.v.push_back(t);
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, const Matrix m) {
        for (int i = 0; i < m.r; i++) {
            for (int j = 0; j < m.c; j++) {
                os << m.v[i * m.r + j] << ' ';
            }
        }
        return os;
    }

public:

    Matrix() : r(0), c(0) {}


    Matrix operator+(const Matrix m) {
        Matrix m0;
        if (r != m.r && c != m.c)
            cout << "ERROR";
        else {
            vector<int> t;
            for (int i = 0; i < r * c; i++) {
                t.push_back(v[i] + m.v[i]);
            }
            m0.r = r;
            m0.c = c;
            m0.v = t;
        }
        return m0;
    }

    Matrix operator-(const Matrix m) {
        Matrix m0;
        if (r != m.r && c != m.c)
            cout << "ERROR";
        else {
            vector<int> t;
            for (int i = 0; i < r * c; i++) {
                t.push_back(v[i] - m.v[i]);
            }
            m0.r = r;
            m0.c = c;
            m0.v = t;
        }
        return m0;
    }

    Matrix operator*(const Matrix m) {
        vector<int> t;
        for (int i = 0; i < r * m.c; i++) {
            t.push_back(0);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < m.c; k++) {
                    t[i * r + k] += v[i * c + j] * m.v[j * r + k];
                }
            }
        }
        Matrix m0;
        m0.r = r;
        m0.c = r;
        m0.v = t;
        return m0;
    }

private:
    vector<int> v;
};

int main() {

    Matrix m1, m2;
    char op;
    while (cin >> m1 >> op >> m2) {
        switch (op) {
            case '+':
                cout << m1 + m2 << endl;
                break;
            case '-':
                cout << m1 - m2 << endl;
                break;
            case '*':
                cout << m1 * m2 << endl;
                break;
        }
    }
}
