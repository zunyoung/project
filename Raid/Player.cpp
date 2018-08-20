#include "main.h"

void Player::ReduceHp(int &stagecount,int &hp)
{
	if (stagecount > 0 && stagecount < 5)
		hp -= 10;
	else if (stagecount == 5)
		hp -= 20;
	else if (stagecount > 5 && stagecount < 10)
		hp -= 15;
	else if (stagecount == 10)
		hp -= 30;
	else if (stagecount > 10 && stagecount < 15)
		hp -= 20;
	else if (stagecount == 15)
		hp -= 50;
}