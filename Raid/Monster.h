#pragma once
#include "Player.h"
class Monster:
	public Player
{
public:
	int timelimit=10;
	int attacknumber=3;
	char defensekeyword[20];

	void NormalAttack(int &stagecount,int &hp);
	void MakeAttackKeyword();
	void SetLevel(int &stagecount);
	void MonsterAttack(int &stagecount, int &hp);
};