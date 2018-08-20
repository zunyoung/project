#include <iostream>
#include <stdlib.h>
#include "main.h"
using namespace std;

int main()
{
	
	Player Player;
	Monster Monster;
	Boss Boss;
	cout << "레이드" << endl;
	
	clock_t start, end;
	double result = 0;

	start = clock();

	while (1)
	{
		if (Player.hp == 0)
		{
			for (int i = 0; i < 7; i++)
			{
				cout << "GAME OVER..." << endl;
			}
			break;
		}	
		else if (Player.stagecount == 16)
		{
			for (int i = 0; i < 7; i++)
			{
				cout << "CLEAR!!!!!!!!!" << endl;
			}
			break;
		}
		else if (Player.stagecount % 5 == 0)
		{
			cout << "STAGE :" << Player.stagecount << endl;
			cout << "!!! 보스몬스터 출현!!! 윽!! 이것은 너무 강하다!!! !!!" << endl;			
			Boss.BossAttack(Boss.deathcount,Player.stagecount,Player.hp);
			if (Boss.deathcount == 3)
				Player.hp = 0;
			else
			{
				Player.stagecount++;
				Boss.deathcount = 0;
			}
				
		}
		else
		{
			cout << "STAGE :" << Player.stagecount << endl;
			Monster.MonsterAttack(Player.stagecount,Player.hp);
		}
		cout << "HP : " << Player.hp << endl;
	}
	end = clock();

	result += (double)(end - start)/1000;
	
	cout << "걸린 시간 : " << int(result) << endl;
	
	
	return 0;
}