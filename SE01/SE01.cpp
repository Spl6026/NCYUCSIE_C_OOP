#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

struct studentType {
    string FName;
    string LName;
    int tScore;
    char grade;
};

void getData(ifstream &input, studentType sList[], int listSize) {
    input.open("chp09_ex02.txt");
    for (int i = 0; i < listSize; i++) {
        string s;
        stringstream ss;
        getline(input, s);
        ss << s;
        ss >> sList[i].FName >> sList[i].LName >> sList[i].tScore;
    }
    input.close();
}

void calculateGrade(studentType sList[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (sList[i].tScore > 89)
            sList[i].grade = 'A';
        else if (sList[i].tScore > 79)
            sList[i].grade = 'B';
        else if (sList[i].tScore > 69)
            sList[i].grade = 'C';
        else if (sList[i].tScore > 59)
            sList[i].grade = 'D';
        else
            sList[i].grade = 'F';
    }
}

int highestScore(const studentType sList[], int listSize) {
    int Max = 0;
    int maxIndex;
    for (int i = 0; i < listSize; i++) {
        if (sList[i].tScore > Max) {
            Max = sList[i].tScore;
            maxIndex = i;
        }
    }
    return maxIndex;
}

void printResult(ofstream &output, const studentType sList[], int listSize, int maxIndex) {
    output.open("chp09_ex02_out.txt");
    const int Max = sList[maxIndex].tScore;
    string Name[listSize];
    output<< setw(23)<<left<<"Student Name"<<"Test Score  Grade"<<endl;
    for (int i = 0; i < listSize; i++) {
        Name[i] = sList[i].LName + ", " + sList[i].FName;
        output << setw(29) <<left<<Name[i];
        output << setw(8) << sList[i].tScore << sList[i].grade << endl;
    }
    output<<endl;
    output << "Highest Test Score: " << Max << endl;
    output<<"Students having the highest test score: "<<endl;
    for(int i=0;i<listSize;i++)
        if(sList[i].tScore == Max)
            output<<Name[i]<<endl;
    output.close();
}

int main() {
    const int listSize = 20;
    studentType sList[listSize];
    ifstream input;
    getData(input, sList, listSize);
    calculateGrade(sList, listSize);
    int maxIndex = highestScore(sList, listSize);
    ofstream output;
    printResult(output, sList, listSize, maxIndex);
}
