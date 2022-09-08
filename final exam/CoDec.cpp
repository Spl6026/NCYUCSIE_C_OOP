#include <iostream>
#include <map>

using namespace std;

class CoDec {

    map<char, char> enc, dec;
    map<char, char>::iterator it;

public:
    CoDec(string text, string cipher) {
        for (int i = 0; i < text.size(); i++) {
            enc[text[i]] = cipher[i];
            dec[cipher[i]] = text[i];
        }
    }

    string encode(string text) {
        string s;
        for (char &i: text) {
            if (enc[i])
                s += enc[i];
            else
                s += i;
        }
        return s;
    }

    string decode(string cipher) {
        string s;
        for (char &i: cipher) {
            if (dec[i])
                s += dec[i];
            else
                s += i;
        }
        return s;
    }
};

int main() {

    string s0, s1;

    cin >> s0 >> s1;

    CoDec codec = CoDec(s0, s1);

    while (cin >> s0) {

        switch (s0[0]) {

            case '+':
                cout << codec.encode(s0) << endl;
                break;
            case '-':
                cout << codec.decode(s0) << endl;
                break;
        }
    }

}
