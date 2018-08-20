#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

int main()
{
	/*int attack;
	int skill;
	int hp;
	int monster;*/
	int level=0;
	char inputkeyword[20];
	clock_t start, end; 
	char defensekeyword[] = "SEESEEDONTSEE";
	int count = 1;


	while (count)
	{
		for (int i = 0; i < 13; i++)
		{
			cout << "Lv." << i + 1 << "몬스터" << endl;
			cout << "몬스터가 공격을 한다!" << endl;
			cout << defensekeyword << endl;
			

			start = clock();

			for (int j = 0; j < 10; j++)
			{
				Sleep(500);
			}
			
			end = clock();
			cin >> inputkeyword;

			/*if ((float(end - start)) > 3)
			{
				cout << "11" << endl;
			}*/

			for (int i = 0; i < 13; i++)
			{
				if (defensekeyword[i] != inputkeyword[i])
				{
					cout << "방어에 실패했다!" << endl;
					break;
				}
				else if(i == 12)
				{
					cout << "방어에 성공했다!" << endl;
				}
			}
			
		}
	}
	



	return 0;
}
