// namelsit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <bitset>
#define  s 8
#define  m 4
int counter0 = 0;
char value ;
int coun1 = 0;
int flag = 0;
using namespace std;
bitset<s> to_binary(char c)
{
	bitset<s> b1(c);

	return b1;

}
bitset<m> dectobinary(int count)
{ 
	bitset<m> b(count);
	return b;
}
fstream e;
void Display(int n)
{ 
	if (!e.is_open())
	{
		e.open("compresed.txt", ios::app);
	}

	e << dectobinary(n);
	e.close();
}

void counterCheck()
{
	while (counter0 % 15 != 0)
	{
		Display(counter0);
		counter0 = counter0 - 15;
		if (counter0 < 0)
			break;
	}
	if (coun1 >= 2)
	{
		Display(0);
	}

}
void Encoding()
{
	bool toggle = false;
	fstream f1;
	f1.open("binary.txt", ios::in);
	if (!f1.is_open())
	{
		cout << "the problem at me" << endl;
	}
	
	while (!f1.eof())
	{
		value = f1.get();
		cout << value;
		if (value =='0')
		{
			if (toggle == false && flag >= 1)
			{
				counterCheck();

			}
			toggle = true;
			coun1 = 0;
			++counter0;
			flag++;
		}
		else //value = 1
		{
			if (toggle == true)
			{

				counterCheck();
			}
			toggle = false;
			counter0 = 0;
			if (flag == 0 && coun1 == 0)
			{
				counterCheck();
				++coun1;
			}
			else
			{
				++coun1;
			}

		}
	}
	if (value +1 == 0)
			Display(0);

	f1.close();
}
void read_file()
{
	char my_char;
	int num_of_lines = 0;
	fstream fin;
	fstream fout;
	fout.open("binary.txt", ios::out);
	if (!fout.is_open())
	{
		cout << " the problem is at binary file !  " << endl;
	}
	fin.open("namelist.txt", ios::in);
	if (!fin.is_open())
	{
		cout << " the problem is at name list file !  " << endl;
	}

	while (fin.get(my_char))
	{
		
		if (my_char == ' '||my_char =='\n') continue;
		//	cout << "wait until finish coverting ..." << endl;
		fout << to_binary(my_char);
		cout << to_binary(my_char) << endl;
	}
	
	fin.close();
	fout.close();
}



int main()
{ 
	//read();
	read_file();
	Encoding();
	//counterCheck();
	/*fstream f;
	bool c;
	f.open("binary.txt",ios::in);
	while (!f.eof())
	{
		f >> c;
		cout << c << endl;
	}
	f.close();*/

	while (true)
	{

	}

	return 0;
}
