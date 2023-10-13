#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    system("cls");
    cout << "Gary Daniel Erno" << endl;
    gotoxy(10, 10);
    cout << "Gary Daniel Erno" << endl;

    cout << "Press any key to clear the screen\n";
    cout << "This line will be deleted when you press a key\n";

    getch();
    // delline();

    // getch();

    // system("cls");

    return 0;
}