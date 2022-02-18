#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMIES.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
ENEMIES::ENEMIES(class GAME* game) :
	GAME_OBJECT(game) {
}
ENEMIES::~ENEMIES() {
	delete[] Enemies;
}
void ENEMIES::create() {
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMIES::init() {
	Enemy.centerPos = game()->container()->enemy().centerPos;

	//3.14がラジアン値で180度、2倍にすることにより360度になる
	float divTheta = 3.14159265f * 2 / Enemy.totalNum;
	float divInterval = Enemy.triggerInterval / Enemy.totalNum;
	for (int i = 0; i < Enemy.totalNum; i++) {
		Enemies[i].ofstTheta = divTheta * i;
		Enemies[i].triggerErapsedTime = divInterval * i;
		Enemies[i].invincibleRestTime = 0;
		Enemies[i].hp = Enemy.initHp;
	}
	//リプレイの時に必要
	Enemy.curNum = Enemy.totalNum;
}
void ENEMIES::update() {
	caunt();
	move();
	launch();
	collision();
}
void ENEMIES::move() {
	if (Enemy.centerPos.x > Enemy.targetPosX) {
		Enemy.centerPos.x -= Enemy.fallSpeed * delta;
	}
	for (int i = 0; i < Enemy.curNum; i++) {
		float theta = Enemy.refTheta + Enemies[i].ofstTheta;
		float px = Enemy.centerPos.x + cos(theta) * Enemy.majRadius;
		float py = Enemy.centerPos.y + sin(theta) * Enemy.minRadius;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}
	Enemy.refTheta += Enemy.thetaSpeed * delta;
}
void ENEMIES::launch() {
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < Enemy.curNum; i++) {
		Enemies[i].triggerErapsedTime += delta;
		if (Enemies[i].triggerErapsedTime >= Enemy.triggerInterval) {
			//敵の位置からプレイヤーの位置へのベクトル、発射方向
			VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
			//エネミーの弾をエネミーの下から発射する
			VECTOR2 pos = Enemies[i].pos + launchVec * Enemy.ofstLaunchDist;
			game()->enemyBullets()->launch(pos, launchVec);
			Enemies[i].triggerErapsedTime = 0;
		}
	}
}
void ENEMIES::collision() {
	BULLETS* bullets = game()->playerBullets();
	float distance = Enemy.bcRadius + bullets->bcRadius();
	//sqDistanceよりも近かったらあたるという判定
	float sqDistance = distance * distance;
	for (int j = Enemy.curNum - 1; j >= 0; j--) {
		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= delta;
		}
		else {
			Enemies[j].color = Enemy.normalColor;
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp--;
					Enemies[j].invincibleRestTime = Enemy.invincibleTime;
					Enemies[j].color = Enemy.collisionColor;
					if (Enemies[j].hp <= 0) {
						Enemy.curNum--;
						Enemies[j] = Enemies[Enemy.curNum];
					}

					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}
void ENEMIES::caunt() {
	if (Enemy.curNum <= 0) {
		Enemy.centerPos = game()->container()->enemy().centerPos;

		//3.14がラジアン値で180度、2倍にすることにより360度になる
		float divTheta = 3.14159265f * 2 / Enemy.totalNum;
		float divInterval = Enemy.triggerInterval / Enemy.totalNum;
		for (int i = 0; i < Enemy.totalNum; i++) {
			Enemies[i].ofstTheta = divTheta * i;
			Enemies[i].triggerErapsedTime = divInterval * i;
			Enemies[i].invincibleRestTime = 0;
			Enemies[i].hp = Enemy.initHp;
		}
		//リプレイの時に必要
		Enemy.curNum = Enemy.totalNum;
	}
}
void ENEMIES::draw() {
	for (int i = 0; i < Enemy.curNum; i++) {
		imageColor(Enemies[i].color);
		image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y, 0, 6);
	}
}
