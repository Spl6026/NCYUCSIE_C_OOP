#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class studentType {
public:
    void set_FName(string);

    void set_LName(string);

    void set_TScore(int);

    void set_Grade(char);

    void get_FName(string &) const;

    void get_LName(string &) const;

    void get_TScore(int &) const;

    void get_Grade(char &) const;

    void get_data(string &, string &, int &, char &) const;

    studentType();

    studentType(string, string, int);

    studentType(string, string, int, char);

    ~studentType();

private:
    string FName;
    string LName;
    int TScore;
    char Grade;
};

void getData(ifstream &input, studentType sList[], int listSize) {
    string first, last;
    int score;
    input.open("ch09_ex02.txt");
    for (int i = 0; i < listSize; i++) {
        input >> first >> last >> score;
        studentType newStu(first, last, score);
        sList[i] = newStu;
    }
    input.close();
}

void calculateGrade(studentType sList[], int listSize) {
    int score;
    char grade;
    for (int i = 0; i < listSize; i++) {
        sList[i].get_TScore(score);
        if (score > 89)
            grade = 'A';
        else if (score > 79)
            grade = 'B';
        else if (score > 69)
            grade = 'C';
        else if (score > 59)
            grade = 'D';
        else
            grade = 'F';
        sList[i].set_Grade(grade);
    }
}

int highestScore(const studentType sList[], int listSize) {
    int max = 0;
    for (int i = 0; i < listSize; i++) {
        int score;
        sList[i].get_TScore(score);
        if (score > max)
            max = score;
    }
    return max;
}

void printResult(ofstream &output, const studentType sList[], int listSize, int max) {
    string first, last;
    int score;
    char grade;
    output.open("ch09_ex02_out.txt");
    string Name[listSize];
    output << setw(23) << left << "Student Name" << "Test Score  Grade" << endl;
    for (int i = 0; i < listSize; i++) {
        sList[i].get_data(first, last, score, grade);
        Name[i] = last + ", " + first;
        output << setw(29) << left << Name[i];
        output << setw(8) << score << grade << endl;
    }
    output << endl;
    output << "Highest Test Score: " << max << endl;
    output << "Students having the highest test score: " << endl;
    for (int i = 0; i < listSize; i++) {
        sList[i].get_TScore(score);
        if (score == max)
            output << Name[i] << endl;
    }
    output.close();
}

int main() {
    const int listSize = 20;
    studentType sList[listSize];
    ifstream input;
    getData(input, sList, listSize);
    calculateGrade(sList, listSize);
    int max = highestScore(sList, listSize);
    ofstream output;
    printResult(output, sList, listSize, max);
}

void studentType::set_FName(string first) {
    FName = first;
}

void studentType::set_LName(string last) {
    LName = last;
}

void studentType::set_TScore(int score) {
    TScore = score;
}

void studentType::set_Grade(char grade) {
    Grade = grade;
}

void studentType::get_FName(string &first) const {
    first = FName;
}

void studentType::get_LName(string &last) const {
    last = LName;
}

void studentType::get_TScore(int &score) const {
    score = TScore;
}

void studentType::get_Grade(char &grade) const {
    grade = Grade;
}

void studentType::get_data(string &first, string &last, int &score, char &grade) const {
    get_FName(first);
    get_LName(last);
    get_TScore(score);
    get_Grade(grade);
}

studentType::studentType() {
    FName = "";
    LName = "";
    TScore = 0;
    Grade = ' ';
}

studentType::studentType(string first, string last, int score) {
    set_FName(first);
    set_LName(last);
    set_TScore(score);
}

studentType::studentType(string first, string last, int score,char grade) {
    set_FName(first);
    set_LName(last);
    set_TScore(score);
    set_Grade(grade);
}

studentType::~studentType() {
    cout << FName << " " << LName << " end" << endl;
}


