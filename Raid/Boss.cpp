#include "main.h"

void Boss::SetLevel(int &stagecount)
{
	if (stagecount == 5)
	{
		timelimit = 12;
		attacknumber = 3;
	}
	else if (stagecount == 10)
	{
		timelimit = 10;
		attacknumber = 4;
	}
	else if (stagecount == 15)
	{
		timelimit = 7;
		attacknumber = 5;
	}
}

void Boss::MakeBossAttackKeyword()
{
	srand((unsigned int)time(NULL));

	char Alphabet[6] = { "UVCG" };

	for (int i = 0; i < 20; i++) // 에러나면 여기. defenskeyword 배열 크기 확인
	{
		defensekeyword[i] = Alphabet[rand() % 4];
	}
}

void Boss ::BlindAttack(int &deathcount, int &stagecount, int &hp)
{
	clock_t start, end;
	double result = 0;
	char inputkeyword[20];
	int sw = 1;
	MakeAttackKeyword();

	cout << "보스가 블라인드 스킬을 사용했다!" << endl;

	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			cout << "?";
		else
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
					cout << "느려서 방어에 실패했다!"<<hp << endl;		
					cout << "hp=" << hp << endl;
					deathcount++;
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
					cout << "느려서 방어에 실패했다!"<<hp << endl;	
					cout << "hp=" << hp << endl;
					deathcount++;
					sw = 0;
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

void Boss::ReverseAttack(int &deathcount, int &stagecount, int &hp)
{
	clock_t start, end;
	double result = 0;
	char inputkeyword[20];
	int sw = 1;

	MakeAttackKeyword();

	cout << "보스가 반전 스킬을 사용했다!" << endl;

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
			if (defensekeyword[9-i] != inputkeyword[i])
			{
				end = clock();
				result += (double)(end - start);
				cout << timelimit - ((int)result / 1000) << endl;
				if (timelimit - ((int)result / 1000) < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!"<<hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
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
					cout << "느려서 방어에 실패했다!" <<hp<< endl;
					cout << "hp=" << hp << endl;
					deathcount++;
					sw = 0;
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

void Boss::StunAttack(int &deathcount, int &stagecount, int &hp)
{
	Player Player;
	clock_t start, end;
	double result = 0;
	char inputkeyword[20];
	int sw = 1;

	MakeAttackKeyword();

	cout << "보스가 스턴 스킬을 사용했다!" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << defensekeyword[i];
	}
	cout << endl;
	while (sw)
	{
		start = clock();
		if (result == 0)
		{
			cout << "3초간 스턴에 걸렸다!" << endl;
			Sleep(3000);
		}
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
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
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
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
					sw = 0;
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
void Boss::OddNumberAttack(int &deathcount, int &stagecount, int &hp)
{
	Player Player;
	clock_t start, end;
	double result = 0;
	int sw = 1;
	int k = 0;
	char inputkeyword[20];
	MakeAttackKeyword();


	cout << "보스의 홀! 스킬에 대비하자!" << endl;
	_sleep(1000);
	for (int i = 0; i < 10; i++)
	{
		cout << defensekeyword[i];
	}
	cout << endl;
	while (sw)
	{

		start = clock();
		cin >> inputkeyword;
		for (int i = 0; i < 10; i += 2)
		{
			k = i / 2;

			if (defensekeyword[i] != inputkeyword[k])
			{

				end = clock();
				cout << "스킬 방어에 실패했다!" << endl;

				result += (double)(end - start);
				cout << timelimit - ((int)result) / 1000 << endl;

				if (timelimit - ((int)result) / 1000 < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
					sw = 0;
					break;
				}
				break;
			}
			else if (k == 4)
			{
				end = clock();

				cout << "방어는 효과적이었다! " << endl;
				result += (double)(end - start);
				cout << timelimit - ((int)result) / 1000 << endl;

				if (timelimit - ((int)result) / 1000 < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
					
					sw = 0;
					break;
				}
				cout << "다음 공격에 대비하자!" << endl;
				_sleep(2000);

				system("cls");
				sw = 0;

			}
		}


	}
}

void Boss::EvenNumberAttack(int &deathcount,int &stagecount, int &hp)
{
	Player Player;
	clock_t start, end;
	double result = 0;
	int sw = 1;
	int k = 0;
	char inputkeyword[20];
	MakeAttackKeyword();


	cout << "보스의 짝! 스킬에 대비하자!" << endl;
	_sleep(1000);
	for (int i = 0; i < 10; i++)
	{
		cout << defensekeyword[i];
	}
	cout << endl;
	while (sw)
	{

		start = clock();
		cin >> inputkeyword;
		for (int i = 1; i < 10; i += 2)
		{
			k = (i - 1) / 2;

			if (defensekeyword[i] != inputkeyword[k])
			{

				end = clock();
				cout << "스킬 방어에 실패했다!" << endl;

				result += (double)(end - start);
				cout << timelimit - ((int)result) / 1000 << endl;

				if (timelimit - ((int)result) / 1000 < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
					sw = 0;
					break;
				}
				break;
			}
			else if (k == 4)
			{
				end = clock();

				cout << "방어는 효과적이었다! " << endl;
				result += (double)(end - start);
				cout << timelimit - ((int)result) / 1000 << endl;

				if (timelimit - ((int)result) / 1000 < 0)
				{
					ReduceHp(stagecount,hp);
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
					sw = 0;
					break;
				}
				cout << "다음 공격에 대비하자!" << endl;
				_sleep(2000);

				system("cls");
				sw = 0;

			}
		}


	}
}
void Boss::NormalAttack(int &deathcount, int &stagecount, int &hp)
{
	Player Player;
	clock_t start, end;
	double result = 0;
	char inputkeyword[20];
	int sw = 1;

	MakeBossAttackKeyword();

	cout << "보스의 일반 공격을 사용했다!" << endl;

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
					cout << "느려서 방어에 실패했다!" << hp << endl;
					cout << "hp=" << hp << endl;
					deathcount++;
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
					ReduceHp(deathcount,hp);
					cout << "느려서 방어에 실패했다!" << hp << endl;
					deathcount++;
					sw = 0;
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
void Boss::BossAttack(int &deathcount, int &stagecount,int &hp)
{
	int i;
	SetLevel(stagecount);
	srand((unsigned int)time(NULL));
	for (int j = 0; j < attacknumber;j++)
	{
		if (deathcount == 3)
			break;
		if (hp == 0)
			break;
		i =  rand() % 6;
		switch (i) 
		{
		case 0:
			StunAttack(deathcount, stagecount,hp);
			break;
		case 1:
			NormalAttack(deathcount, stagecount,hp);
			break;
		case 2:
			ReverseAttack(deathcount, stagecount,hp);
			break;
		case 3:
			OddNumberAttack(deathcount, stagecount,hp);
			break;
		case 4:
			EvenNumberAttack(deathcount, stagecount,hp);
			break;
		case 5:
			BlindAttack(deathcount, stagecount, hp);
			break;
		}
	}
}