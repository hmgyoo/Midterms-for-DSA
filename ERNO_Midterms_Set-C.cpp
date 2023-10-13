// Write a program that read a file with a filename DAILYSALES.DAT that contains the weekly sales of all the products in a Milk Tea Shop.

// Your program should be able to total all the sales per product in the Milk Tea Shop and arrange the product items with the highest amount of sales down to the lowest sales.

// The data file for each product contains 4 weekly data sales. Compute the total weekly sales for all the products. For example, see the sample output below:

// Product Item                    Week 1               Week 2               Week 3               Week 4                       Total Sales

// Wintermelon                   3000                    1500                    2000                    1000                            7,500

// Okinawa                          2000                    2000                    1000                    1300                             6,300

// Matcha                            1000                    1000                    1500                    2000                             5,500

// Taro                                 2000                    1000                    1000                    1400                             5,400

// Hokkaido                        1000                    1300                    1000                    1500                             4,800

// Weekly Sales                    9,000                   6,800                   6,500                   7,200                           29,500

// Save the SALES REPORT in a file with a filename SALES.dat

// The file should contain the product item and the weekly sales and total sales similar to the sales report example.

// Name: Gary Daniel I. Erno
// Course: CPE 0211.1-3
// Midterms Exam Part 2, Set B (unable to change file name due to lack of time)

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Product
{
    string name;
    int week1;
    int week2;
    int week3;
    int week4;
    int total = 0;

    void totalProd()
    {
        total = week1 + week2 + week3 + week4;
    }
};

int totalWeek1(vector<Product> &prod)
{
    int total = 0;
    for (int i = 0; i < prod.size() - 1; i++)
    {
        total += prod[i].week1;
    }

    return total;
}

int totalWeek2(vector<Product> &prod)
{
    int total = 0;
    for (int i = 0; i < prod.size() - 1; i++)
    {
        total += prod[i].week2;
    }

    return total;
}

int totalWeek3(vector<Product> &prod)
{
    int total = 0;
    for (int i = 0; i < prod.size() - 1; i++)
    {
        total += prod[i].week3;
    }

    return total;
}

int totalWeek4(vector<Product> &prod)
{
    int total = 0;
    for (int i = 0; i < prod.size() - 1; i++)
    {
        total += prod[i].week4;
    }

    return total;
}

// int sumTotal(int week1, int week2, int week3, int week4)
// {
//     int sumTotal = 0;
//     sumTotal = week1 + week2 + week3 + week4;
//     return sumTotal;
// }

int prodTotal(vector<Product> &prod)
{
    int total = 0;
    for (int i = 0; i < prod.size() - 1; i++)
    {
        total += prod[i].total;
    }

    return total;
}

void toVector(vector<Product> &prod, ifstream &origFile)
{
    Product temp;
    string name;
    int week1;
    int week2;
    int week3;
    int week4;

    while (origFile.eof() == 0)
    {
        origFile >> name >> week1 >> week2 >> week3 >> week4;
        temp.name = name;
        temp.week1 = week1;
        temp.week2 = week2;
        temp.week3 = week3;
        temp.week4 = week4;
        temp.totalProd();
        prod.push_back(temp);
    }
}

void display(vector<Product> &prod)
{
    cout << setfill('*') << setw(130) << '*' << endl;
    cout << setfill(' ');
    cout << left << setw(30) << "Product Name" << setw(20) << "Week 1" << setw(20) << "Week 2" << setw(20) << "Week 3" << setw(20) << "Week 4" << setw(20) << "Total Sales" << endl;
    cout << setfill('*') << setw(130) << '*' << endl;
    cout << setfill(' ');

    for (int i = 0; i < prod.size() - 1; i++)
    {
        cout << left << setw(30) << prod[i].name << setw(20) << prod[i].week1 << setw(20) << prod[i].week2 << setw(20) << prod[i].week3 << setw(20) << prod[i].week4 << setw(20) << prod[i].total << endl;
    }

    cout << endl;
    cout << left << setw(30) << "Weekly Sales" << setw(20) << totalWeek1(prod) << setw(20) << totalWeek2(prod) << setw(20) << totalWeek3(prod) << setw(20) << totalWeek4(prod) << setw(20) << prodTotal(prod);
}

void savetoFile(vector<Product> &prod, ofstream &newFile)
{
    newFile << setfill('*') << setw(130) << '*' << endl;
    newFile << setfill(' ');
    newFile << left << setw(30) << "Product Name" << setw(20) << "Week 1" << setw(20) << "Week 2" << setw(20) << "Week 3" << setw(20) << "Week 4" << setw(20) << "Total Sales" << endl;
    newFile << setfill('*') << setw(130) << '*' << endl;
    newFile << setfill(' ');

    for (int i = 0; i < prod.size() - 1; i++)
    {
        newFile << left << setw(30) << prod[i].name << setw(20) << prod[i].week1 << setw(20) << prod[i].week2 << setw(20) << prod[i].week3 << setw(20) << prod[i].week4 << setw(20) << prod[i].total << endl;
    }

    newFile << endl;
    newFile << left << setw(30) << "Weekly Sales" << setw(20) << totalWeek1(prod) << setw(20) << totalWeek2(prod) << setw(20) << totalWeek3(prod) << setw(20) << totalWeek4(prod) << setw(20) << prodTotal(prod);
}

int main()
{

    ifstream fin;
    ofstream fout;
    vector<Product> products;

    // open file to read the data
    fin.open("DAILYSALES.DAT");
    if (!fin)
    {
        cout << "\nFile is not open yet.";
    }
    else
    {
        cout << "Opening data file..." << endl;
        toVector(products, fin);
        fin.close();

        //display the data in tabular form
        display(products);

        cout << "\nSaving to SALES.dat..." << endl;
        fout.open("Sales.dat");
        savetoFile(products, fout);
        cout << "\nSaved successfully..." << endl;
    }

    return 0;
}