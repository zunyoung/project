#pragma once
class Player
{
public:
	int stagecount = 1;
	int hp=100;
	void ReduceHp(int &stagecount, int &hp);
};