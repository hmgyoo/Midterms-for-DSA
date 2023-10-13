#include <iostream>
#include <windows.h> //for_sleep()_function
#include <iomanip>	 // for_setidth_function
#include <fstream>
#include <process.h> //For_exit(0)
#include <conio.h>	 //for_getch()
#include <string.h>
#include <stdio.h> //for_gets()

int k = 0, sys, str, high = 60; //For_student_object_handling
using namespace std;

class person
{
protected:
	char sex;
	int age;
	int count;
	char name[50];

public:
	int length;
	void readperson()
	{
		system("CLS");
		cout << "\t\t************************************************";
		cout << "\n\t\t\t\tADD A NEW STUDENT ";
		cout << "\n\t\t************************************************";
		cout << "\n\n Good name please (Don't Use space; use '_') :";
		cin >> name;
		cout << "\n Please Enter your age :";
		cin >> age;
		cout << "\n Sex ? (M/F) :";
		cin >> sex;
	}
};
class student : public person //This_class_student_is_inherited_from_class_person.

{
protected:
	int roll;
	int avmark;

public:
	void readstudent()
	{
		cout << "\n\n Enter your Roll Number :";
		cin >> roll;
		cout << "\n Enter Your Average Mark( Out of hundred ) :";
		cin >> avmark;
	}
	int getroll()
	{
		return (roll);
	}
	void getdetails()
	{
		cout << "\n\n Name  :" << name;
		cout << "\n Sex   :" << sex;
		cout << "\n Age   :" << age;
		cout << "\n Roll  :" << roll;
		cout << "\n Mark  :" << avmark;
	}
	void GetDetailsTable() //For_making_table_arrangement_of_students;
	{
		high--;
		str = strlen(name);
		if (str <= 7) //For_maintaining_the_exact_form; One_extra_\t_is_used_after_name;
			cout << "\n\t\t" << name << "\t\t" << sex << "\t" << age << "\t" << roll << "\t" << avmark << "\n";
		else
			cout << "\n\t\t" << name << "\t" << sex << "\t" << age << "\t" << roll << "\t" << avmark << "\n";
	}
	int getmark()
	{
		return (avmark);
	}
	void prtname()
	{
		cout << name;
	}
	char GetSex()
	{
		return sex;
	}

} stu[61];
// Class_Defnition_completed

int main() //Beggining_main_function_HERE

{

	void SortBySex();
	void SortItOnMark();
	void SortItOnRoll();
	ofstream fout;
	ifstream fin;
start: //For_returning_into_main_menu
	fin.close();
	fout.close();
	fin.open("student.dat", ios::app | ios::binary | ios::in);
	int num = 0; //Making_input_buffer_zero_after_function_returning_through_start:
	while (fin)	 // Taking Student details into memory
	{
		fin.read((char *)&stu[num], sizeof(stu[num]));
		++num;
	}
	//File_input_completed !
	sys = num - 1;
	int p1 = 100, p2 = 50;
	system("color f1");
	int k, Ru, rank(0), rankm(0);
	system("CLS");
	cout << "\t\t************************************************";
	cout << setw(62) << "MAIN MENU";
	cout << "\n\t\t************************************************";
	cout << "\n\n\n 1.Student Details"
		 << "\n 2.Best Student"
		 << "\n 3.Get Mark"
		 << "\n 4.Add a new student"
		 << "\n 5.View all students"
		 << "\n 6.Exit\t\t\t\t\t\t\t\t99.Reset all!!!"
		 << "\n\n\n Enter your selection :";
	cin >> k;
	switch (k)
	{ //switch_starts
	case 1:
		system("cls");
		int flag;
		flag = 0;
		cout << "\t\t************************************************";
		cout << "\n\t\t\t\tSTUDENT DETAILS";
		cout << "\n\t\t************************************************";
		cout << "\n\nEnter Roll Number :";
		cin >> Ru;
		for (int i = 0; i < 60; ++i)
		{
			if (stu[i].getroll() == Ru)
			{
				flag = 1;
				stu[i].getdetails();
			}
		}
		if (!flag)
			cout << "\n\n\n\nSorry...I cannot find a student with this roll number !";
		cout << "\n\n\n\n\nPress Any key.............";
		if (_getch())
			goto start;

	case 2:
		system("cls");
		cout << "\t\t************************************************";
		cout << "\n\t\t\t\tTHE BEST STUDENT ";
		cout << "\n\t\t************************************************";
		cout << "\n\n Best Student is :";
		for (int i = 0; i < 60; ++i)
		{

			if (stu[i].getmark() > rankm)
			{
				rankm = stu[i].getmark();
				rank = i;
			}
		}
		stu[rank].getdetails();
		cout << "\n\n\n\n\nPress Any key.............";
		if (_getch())
			goto start;
	case 3:
		system("cls");
		flag = 1;
		cout << "\t\t************************************************";
		cout << "\n\t\t\t\tGET THE MARK ";
		cout << "\n\t\t************************************************";
		cout << "\n\n\nPlease Enter Roll Number :";
		cin >> Ru;
		for (int i = 0; i < 60; ++i)
		{
			if (stu[i].getroll() == Ru)
			{
				flag = 0;
				cout << "\n\n\n Mark of ";
				stu[i].prtname();
				cout << " is " << stu[i].getmark();
			}
		}
		if (flag)
			cout << "\n\n\t\tSorry....No Such students; Try again !";
		if (_getch()) //wait_for_any_input_via_keyboard
			goto start;
		break;
	case 4: //Add_student_menu
		stu[k].readperson();
		stu[k].readstudent();
		fout.open("student.dat", ios::out | ios::binary | ios::app);
		fout.write((char *)&stu[k], sizeof(student));
		cout << "\n\n\n\t\t\tFile saving accomplsihed !Please Restart this program ";
		fout.close();
		fin.close();
		cout << "\n\n\n\n\n\n";
		Sleep(2500);
		goto start;

		break;
	case 5: // View_all_students_table
		system("CLS");
		int count, selection;
		char answer;
		answer = 'n';
		count = 0;
		cout << "\t\t************************************************";
		cout << "\n\t\tName\t\tSex\tAge\tRoll\tMark\n";
		cout << "\t\t************************************************";
		cout << sys;
		while (count < sys)
		{
			stu[count].GetDetailsTable();
			count++;
		}
		cout << "\n\n\t\tDo you want to sort it now ? (y/n) :";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\n Sort By :\n\t1. Mark\n\t\t\t2.Roll\n\t\t\t\t\t3.By Sex\n\n";
			cout << "Enter :";
			cin >> selection;
			switch (selection)
			{
			case 1:
				SortItOnMark();
				break;
			case 2:
				SortItOnRoll();
				break;
			case 3:
				SortBySex();
				break;
			default:
				cout << "\nBad Input !";
			}
		}
		else
			goto start;
		cout << "\n\n\n\n";
		system("pause");
		goto start;
	case 6: //Exit_Function
		system("CLS");
		fin.close();
		fout.close();
		cout << "\n\n\n\t\t\t BYE !!!!!!!!!!!!!!!!!!!!!";
		Sleep(1000); //wait_1_second_before_exiting
		exit(0);
		break;

	case 99:
		// File-reset_option_begins
		char ans;
		system("CLS");
		cout << " You have choosen to delete all the user data from this program !.\n\nCaution :You cannot back up your data !\n\nFor further reference make a copy of file (student.dat) from source folder !";
		cout << "\n\n Are you sure want to erase all (y/n)? :";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			ofstream fout;
			fout.open("student.dat", ios::out, ios::binary);
			cout << "\n\n\n\a"
				 << "\t\a\a Task accomplished Successfully !";
		}
		else
			cout << "\n\n"
				 << "\a\tTask aborted, Now returning to main menu";
		Sleep(2500);
		goto start;
		//File_reset_accomplished

	default:
		system("CLS");
		cout << "\a\n\n\n\t\t\tBad input Recieved ! Try Again";
		Sleep(1000);
		goto start;
		break;

	} //switch ended

	return 0;
}

void SortItOnRoll() //Student_Details_table_sorted_on_mark
{
	high = 60;
	int car = sys;
	cout << "\t\t************************************************";
	cout << "\n\t\tName\t\tSex\tAge\tRoll\tMark\n";
	cout << "\t\t************************************************\n";
	int first = 0, place;
	while (car)
	{
		first = 0;
		for (int t = 0; t < (high); ++t)
		{
			if (first <= stu[t].getroll())
			{
				first = stu[t].getroll();
				place = t;
			}
		}
		stu[place].GetDetailsTable();
		stu[place] = stu[high];
		car--;
	}
} //Function_completed
void SortItOnMark() //Student_Details_table_sorted_on_mark
{
	high = 60;
	int car = sys;
	cout << "\t\t************************************************";
	cout << "\n\t\tName\t\tSex\tAge\tRoll\tMark\n";
	cout << "\t\t************************************************\n";
	int first = 0, place;
	while (car)
	{
		first = 0;
		for (int t = 0; t < (high); ++t)
		{
			if (first <= stu[t].getmark())
			{
				first = stu[t].getmark();
				place = t;
			}
		}
		stu[place].GetDetailsTable();
		stu[place] = stu[high];
		car--;
	}
} //Function_completed

void SortBySex() //Student_Details_table_sorted_on_Sex
{
	high = 60;
	int car = sys;
	cout << "\t\t************************************************";
	cout << "\n\t\tName\t\tSex\tAge\tRoll\tMark\n";
	cout << "\t\t************************************************\n";
	for (int t = 0; t < sys; ++t)
	{
		if (stu[t].GetSex() == 'f' || stu[t].GetSex() == 'F')
		{
			stu[t].GetDetailsTable();
		}
		else
			continue;
	}
	cout << endl;
	for (int t = 0; t < sys; ++t)
	{
		if (stu[t].GetSex() == 'm' || stu[t].GetSex() == 'M')
		{
			stu[t].GetDetailsTable();
		}
		else
			continue;
	}

} //Function_completed
