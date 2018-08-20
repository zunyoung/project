#pragma once
class Boss :
	public Monster
{
public:
	int timelimit=7;
	int attacknumber=3;
	int deathcount = 0;

	void BossAttack(int &deathcount, int &stagecount,int &hp);
	void StunAttack(int &deathcount, int &stagecount, int &hp);
	void ReverseAttack(int &deathcount, int &stagecount, int &hp);
	void BlindAttack(int &deathcount, int &stagecount, int &hp);
	void OddNumberAttack(int &deathcount, int &stagecount, int &hp);
	void EvenNumberAttack(int &deathcount, int &stagecount, int &hp);
	void NormalAttack(int &deathcount, int &stagecount, int &hp);
	void SetLevel(int &stagecount);
	void MakeBossAttackKeyword();
};
