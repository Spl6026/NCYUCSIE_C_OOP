#include <iostream>

using namespace std;

void decToBin(int num, int base) {
    string bin;
    string temp;
    while (num != 0 && num != 1) {
        temp = num % base + '0';
        bin = temp + bin;
        num = num / base;
    }
    temp = num + '0';
    bin = temp + bin;
    cout << bin;
}

int main() {
    int decimalNum;
    int base;

    base = 2;

    cout << "Enter number in decimal: ";
    cin >> decimalNum;
    cout << endl;

    cout << "Decimal " << decimalNum << " = ";
    decToBin(decimalNum, base);
    cout << " binary" << endl;
}