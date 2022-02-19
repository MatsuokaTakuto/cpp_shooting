#include"libOne.h"
#include"TITLE.h"
#include"CERECT.h"
#include"STAGE.h"
#include"TRANS_FADE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"ENEMIES_2.h"
#include"BOSS.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"HP_GAUGE.h"
#include"GAME.h"
#include"FOURAN.h"
#include"ORUGA.h"
#include"GATYA_ANIM.h"
#include"GATYA.h"
GAME::GAME() {
	Container = new CONTAINER;

	Title = new TITLE(this);
	Cerect = new CERECT(this);
	Stage = new STAGE(this);

	Game_Over = new GAME_OVER(this);
	Game_Clear = new GAME_CLEAR(this);

	Trans = new TRANS_FADE(this);

	Player = new PLAYER(this);
	Enemies = new ENEMIES(this);
	Enemies2 = new ENEMIES_2(this);
	Boss = new BOSS(this);
	PlayerBullets = new PLAYER_BULLETS(this);
	EnemyBullets = new ENEMY_BULLETS(this);
	HpGauge = new HP_GAUGE(this);

	FouRan = new FOURAN(this);
	Oruga = new ORUGA(this);
	GatyaAnim = new GATYA_ANIM(this);
	Gatya = new GATYA(this);
}
GAME::~GAME() {
	delete Trans;
	delete Title;
	delete Cerect;
	delete Stage;

	delete Game_Over;
	delete Game_Clear;

	delete HpGauge;
	delete EnemyBullets;
	delete PlayerBullets;
	delete Enemies;
	delete Enemies2;
	delete Boss;
	delete Player;

	delete Container;
	delete FouRan;
	delete Oruga;
	delete GatyaAnim;
	delete Gatya;
}
void GAME::run() {
	window(1920, 1080, full);
	hideCursor();
	Container->load();

	Title->create();

	Stage->create();
	Cerect->create();
	Trans->create();

	Game_Over->create();
	Game_Clear->create();

	Player->create();
	PlayerBullets->create();
	Enemies->create();
	Enemies2->create();
	Boss->create();

	EnemyBullets->create();
	HpGauge->create();

	FouRan->create();
	Oruga->create();
	GatyaAnim->create();
	Gatya->create();

	CurScene = Title;
	CurScene->init();
	initDeltaTime();
	while (notQuit) {
		setDeltaTime();
		CurScene->proc();
	}
}
void GAME::setCurScene(class SCENE* scene) {
	CurScene = scene;
	CurScene->init();
}
void GAME::draw() {
	Player->draw();
	Enemies->draw();
	Enemies2->draw();
	Boss->draw();
	PlayerBullets->draw();
	EnemyBullets->draw();
}
