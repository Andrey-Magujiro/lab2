#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <exception>
#include <locale.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	string str1, str2;
	stringstream ss;
	ifstream file;
	int flag = 1;
	file.open("D:\\лабы 3 курс\\с++\\test2.txt");
	try
	{
		if (file.is_open())
		{
			int size = 0;
			int loong = 0;
			int size_1 = 0;
			while (!file.eof())
			{
				if (flag == 1)
				{
					getline(file, str1, '\n');
					int loong = str1.size();
					file.seekg(size_1, ios_base::beg);
					flag = 0;
				}
				getline(file, str1, ' ');
				getline(file, str2, ' ');
				int str_size = str2.size();
				size = size + str_size;
				str_size = str1.size();
				size = size + str_size;
				ss << str2 << " " << str1 << " ";
				if (size == loong)
				{
					ss << endl;
					size_1 = loong;
					flag = 1;
					size = 0;
				}

			}
		}
		else
		{
			throw exception("Не удалось открыть файл !");
		}
		cout << ss.str() << endl;
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}



	file.close();
}