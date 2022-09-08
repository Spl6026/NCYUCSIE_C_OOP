#include <iostream>
#include <set>

using namespace std;

class MySet {
    friend istream &operator>>(istream &is, MySet &S) {
        is >> S.N;
        S.nums.insert(S.N);
        return is;
    }

    friend ostream &operator<<(ostream &os, MySet &S) {
        for (auto e = S.nums.rbegin(); e != S.nums.rend(); e++) {
            os << *e << " ";
        }
        return os;
    }

    set<int> nums;

private:
    int N;

};

int main() {

    int len;

    while (cin >> len) {

        MySet mset;

        for (; len; --len)
            cin >> mset;

        cout << mset << endl;
    }

}
