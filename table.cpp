#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    cout << setfill('*') << setw(55);
    cout << '*' << endl;
    cout << setfill(' ') << left << setw(15) << "Name" << setw(10) << "Sex" << setw(10) << "Age" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill('*') << setw(55);
    cout << '*' << endl;

    cout << setfill(' ') << left << setw(15) << "Gary" << setw(10) << "M" << setw(10) << "13" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Tina" << setw(10) << "F" << setw(10) << "69" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "RastaMan" << setw(10) << "M" << setw(10) << "21" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Bitch" << setw(10) << "M" << setw(10) << "09" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Tangina" << setw(10) << "F" << setw(10) << "60" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Gago" << setw(10) << "F" << setw(10) << "90" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Help bukas" << setw(10) << "F" << setw(10) << "1" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "SHibaInu" << setw(10) << "M" << setw(10) << "12" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Rimuru" << setw(10) << "F" << setw(10) << "34" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Nel" << setw(10) << "M" << setw(10) << "22" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Tanga" << setw(10) << "M" << setw(10) << "111" << setw(10) << "Roll" << setw(10) << "Mark" << endl;
    cout << setfill(' ') << left << setw(15) << "Inutil" << setw(10) << "M" << setw(10) << "6921" << setw(10) << "Roll" << setw(10) << "Mark" << endl;

    int temp = 3;
    int num;
    int count;
    cin >> temp;
    for (count = 0; count <= 3; count++)
    {
        cout << temp << " ";
        temp = temp + num * (count - 1);
    }
    cout << endl;

    int a, b, z;
    a = 1;
    b = 4;
    while (a < b)
    {
        a = 2 * a;
        b = b + 1;
    }
    z = b;
    cout << z;
    return 0;
}