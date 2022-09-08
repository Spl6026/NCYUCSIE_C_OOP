#include <iostream>
#include "partTimeEmployee.h"

void partTimeEmployee::print() const {
    personType::print();
    cout << "'s wages are: $" << calculatePay() << endl;
}

double partTimeEmployee::calculatePay() const {
    return (payRate * hoursWorked);
}

void partTimeEmployee::setNameRateHours(string first, string last, double rate, double hours) {
    personType::setName(first, last);
    payRate = rate;
    hoursWorked = hours;
}

partTimeEmployee::partTimeEmployee(string first, string last, double rate, double hours) : personType(first, last) {
    if (rate >= 0)
        payRate = rate;
    else
        payRate = 0;
    if (hours >= 0)
        hoursWorked = hours;
    else
        hoursWorked = 0;
}