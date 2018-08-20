#include "main.h"

void Monster_0::NormalAttack()
{
	clock_t start, end;
	double result=0;
	int sw = 1;
	char defensekeyword[20] = { "emiyamuljomdao" };
	char inputkeyword[20];
	cout << "일반 공격이 시작되었습니다." << endl;
	for (int i = 0; i < 14; i++)
	{
		cout << defensekeyword[i];
	}
	cout << endl;
	while (sw)
	{
		start = clock();
		cin >> inputkeyword;
		for (int i = 0; i < 14; i++)
		{
			if (defensekeyword[i] != inputkeyword[i])
			{
				cout << "다시 입력하세요" << endl;
				i = 14;
			}
			else if (i == 13)
			{
				cout << "방어에 성공하였습니다." << endl;
				sw = 0;
			}
		}
		end = clock();
		result += (double)(end - start);
		cout << timelimit - (int)result / 1000 << endl;
		if (timelimit - (int)result / 1000 < 0)
		{
			cout << "시간초과"<<endl;
			break;
		}
	}
}