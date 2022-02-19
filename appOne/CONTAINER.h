#pragma once
#include"TITLE.h"
#include"CERECT.h"
#include"STAGE.h"
#include"PLAYER.h"
#include"GAME_OVER.h"
#include"GAME_CLEAR.h"
#include"ENEMIES.h"
#include"ENEMIES_2.h"
#include"BOSS.h"
#include"BULLETS.h"
#include"HP_GAUGE.h"
#include"FOURAN.h"
#include"ORUGA.h"
#include"GATYA_ANIM.h"
#include"GATYA.h"
class CONTAINER
{
	struct DATA {
		ORUGA::DATA oruga;
		TITLE::DATA title;
		CERECT::DATA cerect;
		STAGE::DATA stage;
		GAME_OVER::DATA GameOver;
		GAME_CLEAR::DATA GameClear;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		ENEMIES_2::DATA enemy2;
		BOSS::DATA bossenemy;
		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyBullet;
		HP_GAUGE::DATA hpGauge;
		FOURAN::DATA fouran;
		GATYA_ANIM::DATA GatyaAnim;
		GATYA::DATA Gatya;
	};
	DATA Data;
public:
	~CONTAINER();
	void load();
	void setData();
	void loadGraphic();
	const STAGE::DATA& stage() { return Data.stage; }
	const CERECT::DATA& cerect() { return Data.cerect; }
	const TITLE::DATA& title() { return Data.title; }
	const GAME_OVER::DATA& GameOver() { return Data.GameOver; }
	const GAME_CLEAR::DATA& GameClear() { return Data.GameClear; }
	const PLAYER::DATA& player() { return Data.player; }
	const ENEMIES::DATA& enemy() { return Data.enemy; }
	const ENEMIES_2::DATA& enemy2() { return Data.enemy2; }
	const BOSS::DATA& bossenemy() { return Data.bossenemy; }
	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
	const BULLETS::DATA& enemyBullet() { return Data.enemyBullet; }
	const HP_GAUGE::DATA& hpGauge() { return Data.hpGauge; }
	const FOURAN::DATA& fouran() { return Data.fouran; }
	const ORUGA::DATA& oruga() { return Data.oruga; }
	const GATYA_ANIM::DATA& gatyaanim() { return Data.GatyaAnim; }
	const GATYA::DATA& gatya() { return Data.Gatya; }
};
