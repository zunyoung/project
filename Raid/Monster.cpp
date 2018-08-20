#include "main.h"

void Monster::SetLevel(int &stagecount)
{
	if (stagecount > 0 && stagecount < 5)
	{
		timelimit = 15; 
		attacknumber = 2;
	}		
	else if (stagecount > 5 && stagecount < 10)
	{
		timelimit = 10;
		attacknumber = 3;
	}
	else if (stagecount > 10 && stagecount < 15)
	{
		timelimit = 7;
		attacknumber = 4;
	}
}




void Monster::MakeAttackKeyword()
{
	srand((unsigned int)time(NULL));

	char Alphabet[27] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	
	for (int i = 0; i < 10; i++)
	{
		defensekeyword[i] = Alphabet[rand() % 26];
	}
}

void Monster::NormalAttack(int &stagecount,int &hp)
{
	clock_t start, end;
	double result = 0;
	char inputkeyword[20];
	int sw=1;
	SetLevel(stagecount);
	
	MakeAttackKeyword();

	cout << "몬스터가 일반 공격을 사용했다!" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << defensekeyword[i];
	}

	cout << endl;
	while (sw)
	{
		start = clock();
		cin >> inputkeyword;
		for (int i = 0; i < 10; i++)
		{
			if (defensekeyword[i] != inputkeyword[i])
			{
				end = clock();
				result += (double)(end - start);
				cout << timelimit - ((int)result / 1000) << endl;
				if (timelimit - ((int)result / 1000) < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!" << endl;	
					cout << "hp=" << hp << endl;
					sw = 0;
					break;
				}
				cout << "다시 방어하자!" << endl;
				break;
			}
			else if (i == 9)
			{
				end = clock();
				result += (double)(end - start);
				cout << timelimit - ((int)result / 1000) << endl;
				if (timelimit - ((int)result / 1000) < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!" << endl;	
					cout << "hp=" << hp << endl;
					sw=0;
					break;
				}
				cout << "방어는 효과적이었다!" << endl;
				cout << "다음 공격에 대비하자!" << endl;
				_sleep(2000);
				
				system("cls");
				sw = 0;
			}
		}		
	}
}

void Monster::MonsterAttack(int &stagecount, int &hp)
{
	int i;
	
	for (int j = 0; j < attacknumber; j++)
	{
		NormalAttack(stagecount, hp);
		if (hp == 0)
			break;
	}
	stagecount++;
}
