#include "main.h"

void Monster_0::NormalAttack()
{
	clock_t start, end;
	double result=0;
	int sw = 1;
	char defensekeyword[20] = { "emiyamuljomdao" };
	char inputkeyword[20];
	cout << "�Ϲ� ������ ���۵Ǿ����ϴ�." << endl;
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
				cout << "�ٽ� �Է��ϼ���" << endl;
				i = 14;
			}
			else if (i == 13)
			{
				cout << "�� �����Ͽ����ϴ�." << endl;
				sw = 0;
			}
		}
		end = clock();
		result += (double)(end - start);
		cout << timelimit - (int)result / 1000 << endl;
		if (timelimit - (int)result / 1000 < 0)
		{
			cout << "�ð��ʰ�"<<endl;
			break;
		}
	}
}