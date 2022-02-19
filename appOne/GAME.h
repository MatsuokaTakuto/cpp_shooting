#pragma once
class GAME {
private:
	class CONTAINER* Container = nullptr;
public:
	class CONTAINER* container() { return Container; }
private:
	class TITLE* Title = nullptr;
	class CERECT* Cerect = nullptr;
	class STAGE* Stage = nullptr;

	class GAME_OVER* Game_Over = nullptr;
	class GAME_CLEAR* Game_Clear = nullptr;

	class SCENE* CurScene = nullptr;
	class TRANS* Trans = nullptr;
	class PLAYER* Player = nullptr;
	class ENEMIES* Enemies = nullptr;
	class ENEMIES_2* Enemies2 = nullptr;
	class BOSS* Boss = nullptr;

	class PLAYER_BULLETS* PlayerBullets = nullptr;
	class ENEMY_BULLETS* EnemyBullets = nullptr;
	class HP_GAUGE* HpGauge = nullptr;

	class FOURAN* FouRan = nullptr;
	class ORUGA* Oruga = nullptr;
	class GATYA_ANIM* GatyaAnim = nullptr;
	class GATYA* Gatya = nullptr;
public:
	void draw();
	class TITLE* title() { return Title; }
	class CERECT* cerect() { return Cerect; }
	class STAGE* stage() { return Stage; }

	class GAME_OVER* geme_over() { return Game_Over; }
	class GAME_CLEAR* game_clear() { return Game_Clear; }

	class TRANS* trans() { return Trans; }
	class PLAYER* player() { return Player; }
	class ENEMIES* enemies() { return Enemies; }
	class ENEMIES_2* enemies2() { return Enemies2; }
	class BOSS* bossenemy() { return Boss; }
	class PLAYER_BULLETS* playerBullets() { return PlayerBullets; }
	class ENEMY_BULLETS* enemyBullets() { return EnemyBullets; }
	class HP_GAUGE* hpGauge() { return HpGauge; }

	class FOURAN* fouran() { return FouRan; }
	class ORUGA* oruga() { return Oruga; }
	class GATYA_ANIM* gatyaanim() { return GatyaAnim; }
	class GATYA* gatya() { return Gatya; }
	void setCurScene(class SCENE* scene);
public:
	GAME();
	~GAME();
	void run();
};
