#include "BOSS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "BOSS.h"
#include"HP_GAUGE.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
BOSS::BOSS(class GAME* game) :
	GAME_OBJECT(game) {
}
BOSS::~BOSS() {
	delete[] BossEnemies;
}
void BOSS::create() {
	BossEnemy = game()->container()->bossenemy();
	BossEnemies = new BOSSENEMY[BossEnemy.totalNum];
}
void BOSS::init() {
	BossEnemy.centerPos = game()->container()->bossenemy().centerPos;

	//3.14がラジアン値で180度、2倍にすることにより360度になる
	float divTheta = 3.14159265f * 2 / BossEnemy.totalNum;
	float divInterval = BossEnemy.triggerInterval / BossEnemy.totalNum;
	for (int i = 0; i < BossEnemy.totalNum; i++) {
		BossEnemies[i].ofstTheta = divTheta * i;
		BossEnemies[i].triggerErapsedTime = divInterval * i;
		BossEnemies[i].invincibleRestTime = 0;
		BossEnemies[i].hp = BossEnemy.initHp;
	}
	//リプレイの時に必要
	BossEnemy.curNum = BossEnemy.totalNum;
}
void BOSS::update() {
	move();
	launch();
	collision();
}
void BOSS::move() {
	if (BossEnemy.centerPos.x > BossEnemy.targetPosX) {
		BossEnemy.centerPos.x -= BossEnemy.fallSpeed * delta;
	}
	for (int i = 0; i < BossEnemy.curNum; i++) {
		float theta = BossEnemy.refTheta + BossEnemies[i].ofstTheta;
		float px = BossEnemy.centerPos.x + cos(theta) * BossEnemy.majRadius;
		float py = BossEnemy.centerPos.y + sin(theta) * BossEnemy.minRadius;
		BossEnemies[i].pos.x = px;
		BossEnemies[i].pos.y = py;
	}
	BossEnemy.refTheta += BossEnemy.thetaSpeed * delta;
}
void BOSS::launch() {
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < BossEnemy.curNum; i++) {
		BossEnemies[i].triggerErapsedTime += delta;
		if (BossEnemies[i].triggerErapsedTime >= BossEnemy.triggerInterval) {
			//敵の位置からプレイヤーの位置へのベクトル、発射方向
			VECTOR2 launchVec = normalize(playerPos - BossEnemies[i].pos);
			//エネミーの弾をエネミーの下から発射する
			VECTOR2 pos = BossEnemies[i].pos + launchVec * BossEnemy.ofstLaunchDist;
			game()->enemyBullets()->launch(pos, launchVec);
			BossEnemies[i].triggerErapsedTime = 0;
		}
	}
}
void BOSS::collision() {
	BULLETS* bullets = game()->playerBullets();
	float distance = BossEnemy.bcRadius + bullets->bcRadius();
	//sqDistanceよりも近かったらあたるという判定
	float sqDistance = distance * distance;
	for (int j = BossEnemy.curNum - 1; j >= 0; j--) {
		if (BossEnemies[j].invincibleRestTime > 0) {
			BossEnemies[j].invincibleRestTime -= delta;
		}
		else {
			BossEnemies[j].color = BossEnemy.normalColor;
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = BossEnemies[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					BossEnemies[j].hp--;
					BossEnemies[j].invincibleRestTime = BossEnemy.invincibleTime;
					BossEnemies[j].color = BossEnemy.collisionColor;
					if (BossEnemies[j].hp <= 0) {
						BossEnemy.curNum--;
						BossEnemies[j] = BossEnemies[BossEnemy.curNum];
					}

					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}
void BOSS::caunt() {
	if (BossEnemy.curNum <= 0) {
		BossEnemy.centerPos = game()->container()->bossenemy().centerPos;

		//3.14がラジアン値で180度、2倍にすることにより360度になる
		float divTheta = 3.14159265f * 2 / BossEnemy.totalNum;
		float divInterval = BossEnemy.triggerInterval / BossEnemy.totalNum;
		for (int i = 0; i < BossEnemy.totalNum; i++) {
			BossEnemies[i].ofstTheta = divTheta * i;
			BossEnemies[i].triggerErapsedTime = divInterval * i;
			BossEnemies[i].invincibleRestTime = 0;
			BossEnemies[i].hp = BossEnemy.initHp;
		}
		//リプレイの時に必要
		BossEnemy.curNum = BossEnemy.totalNum;
	}
}
void BOSS::draw() {
	for (int i = 0; i < BossEnemy.curNum; i++) {
		imageColor(BossEnemies[i].color);
		image(BossEnemy.img, BossEnemies[i].pos.x, BossEnemies[i].pos.y, 0, 6);
		game()->hpGauge()->draw(BossEnemy.BossHp, BossEnemy.hpGaugeOfst, BossEnemies[i].hp,0);
	}
}