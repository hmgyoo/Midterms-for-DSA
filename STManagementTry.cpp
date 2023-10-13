#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;
    double studentID;
    double math;
    double science;
    double computer;
    double english;
    double average;

    void getData();
    void showData() const;
    void show_tabular() const;
    int getNum() const;
    void getAverage();
};

void Student::getData()
{
    cout << "\nEnter student's ID no.: ";
    cin >> studentID;
    cout << "\n\nEnter student's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter student's grades below.";
    cout << "\nMath: ";
    cin >> math;
    cout << "\nScience: ";
    cin >> science;
    cout << "\nComputer: ";
    cin >> computer;
    cout << "\nEnglish: ";
    cin >> english;
}

void Student::showData() const
{
    cout << setw(20) << "\nID Number: " << studentID;
    cout << setw(20) << "\nStudent name: " << name;
    cout << setw(20) << "\nMath: " << math;
    cout << setw(20) << "\nScience: " << science;
    cout << setw(20) << "\nComputer: " << computer;
    cout << setw(20) << "\nEnglish: " << english;
}

void Student::show_tabular() const
{
    cout << left << setw(10) << studentID << setw(20) << name << setw(15) << math << setw(15) << science << setw(15) << computer << setw(15) << english << endl;
}

int Student::getNum() const
{
    return studentID;
}

void Student::getAverage()
{
    average = (math + science + computer + english) / 4;
}

void toStudentVector(vector<Student> &mainRecord, ifstream &oldfile)
{
    Student temp;
    string name;
    double studentID;
    double math;
    double science;
    double computer;
    double english;
    double average;

    while (oldfile.eof() == 0)
    {
        oldfile >> studentID >> name >> math >> science >> computer >> english;
        temp.studentID = studentID;
        temp.name = name;
        temp.math = math;
        temp.science = science;
        temp.computer = computer;
        temp.getAverage();
        mainRecord.push_back(temp);
    }
}

int main()
{

    return 0;
}