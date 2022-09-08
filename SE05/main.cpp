#include <iostream>                                 //Line 1
#include "ptrMemberVarType.h"                       //Line 2

using namespace std;                                //Line 3
void testCopyConst(ptrMemberVarType temp);          //Line 4
int main()                                          //Line 5
{                                                   //Line 6
    ptrMemberVarType listOne;                       //Line 7
    int num;                                        //Line 8
    cout << "Line 9: Enter 5 integers." << endl;    //Line 9
    for (int index = 0; index < 5; index++)         //Line 10
    {                                               //Line 11
        cin >> num;                                 //Line 12
        listOne.insertAt(index, num);               //Line 13
    }                                               //Line 14
    cout << "Line 15: listOne: ";                   //Line 15
    listOne.print();                                //Line 16
    cout << endl;                                   //Line 17
    //Declare listTwo and initialize it using listOne
    ptrMemberVarType listTwo(listOne);              //Line 18
    cout << "Line 19: listTwo: ";                   //Line 19
    listTwo.print();                                //Line 20
    cout << endl;                                   //Line 21
    listTwo.insertAt(5, 34);                        //Line 22
    listTwo.insertAt(2, -76);                       //Line 23
    cout << "Line 24: After modifying listTwo: ";   //Line 24
    listTwo.print();                                //Line 25
    cout << endl;                                   //Line 26
    cout << "Line 27: After modifying listTwo, "
         << "listOne: ";                            //Line 27
    listOne.print();                                //Line 28
    cout << endl;                                   //Line 29
    cout << "Line 30: Calling the function testCopyConst"
         << endl;                                   //Line 30
    //Call function testCopyConst
    testCopyConst(listOne);                         //Line 31
    cout << "Line 32: After a call to the function "
         << "testCopyConst, " << endl
         << "         listOne is: ";                //Line 32
    listOne.print();                                //Line 33
    cout << endl;                                   //Line 34
    return 0;                                       //Line 35
}                                                   //Line 36
void testCopyConst(ptrMemberVarType temp)           //Line 37
{                                                   //Line 38
    cout << "Line 39: *** Inside the function "
         << "testCopyConst ***" << endl;            //Line 39
    cout << "Line 40: Object temp data: ";          //Line 40
    temp.print();                                   //Line 41
    cout << endl;                                   //Line 42
    temp.insertAt(3, -100);                         //Line 43
    cout << "Line 44: After changing temp: ";       //Line 44
    temp.print();                                   //Line 45
    cout << endl;                                   //Line 46
    cout << "Line 47: *** Exiting the function "
         << "testCopyConst ***" << endl;           //Line 47
}