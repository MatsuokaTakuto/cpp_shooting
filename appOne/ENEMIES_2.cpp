#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMIES_2.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
ENEMIES_2::ENEMIES_2(class GAME* game) :
	GAME_OBJECT(game) {
}
ENEMIES_2::~ENEMIES_2() {
	delete[] Enemies2;
}
void ENEMIES_2::create() {
	Enemy2 = game()->container()->enemy2();
	Enemies2 = new ENEMY[Enemy2.totalNum];
}
void ENEMIES_2::init() {
	Enemy2.centerPos = game()->container()->enemy2().centerPos;

	//3.14がラジアン値で180度、2倍にすることにより360度になる
	float divTheta = 3.14159265f * 2 / Enemy2.totalNum;
	float divInterval = Enemy2.triggerInterval / Enemy2.totalNum;
	for (int i = 0; i < Enemy2.totalNum; i++) {
		Enemies2[i].ofstTheta = divTheta * i;
		Enemies2[i].triggerErapsedTime = divInterval * i;
		Enemies2[i].invincibleRestTime = 0;
		Enemies2[i].hp = Enemy2.initHp;
	}
	//リプレイの時に必要
	Enemy2.curNum = Enemy2.totalNum;
}
void ENEMIES_2::update() {
	caunt();
	move();
	launch();
	collision();
}
void ENEMIES_2::move() {
	if (Enemy2.centerPos.x > Enemy2.targetPosX) {
		Enemy2.centerPos.x -= Enemy2.fallSpeed * delta;
	}
	for (int i = 0; i < Enemy2.curNum; i++) {
		float theta = Enemy2.refTheta + Enemies2[i].ofstTheta;
		float px = Enemy2.centerPos.x + cos(theta) * Enemy2.majRadius;
		float py = Enemy2.centerPos.y + sin(theta) * Enemy2.minRadius;
		Enemies2[i].pos.x = px;
		Enemies2[i].pos.y = py;
	}
	Enemy2.refTheta += Enemy2.thetaSpeed * delta;
}
void ENEMIES_2::launch() {
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < Enemy2.curNum; i++) {
		Enemies2[i].triggerErapsedTime += delta;
		if (Enemies2[i].triggerErapsedTime >= Enemy2.triggerInterval) {
			//敵の位置からプレイヤーの位置へのベクトル、発射方向
			VECTOR2 launchVec = VECTOR2(-1, 0);
			//エネミーの弾をエネミーの下から発射する
			VECTOR2 pos = Enemies2[i].pos + launchVec * Enemy2.ofstLaunchDist;
			game()->enemyBullets()->launch(pos, launchVec);
			Enemies2[i].triggerErapsedTime = 0;
		}
	}
}
void ENEMIES_2::collision() {
	BULLETS* bullets = game()->playerBullets();
	float distance = Enemy2.bcRadius + bullets->bcRadius();
	//sqDistanceよりも近かったらあたるという判定
	float sqDistance = distance * distance;
	for (int j = Enemy2.curNum - 1; j >= 0; j--) {
		if (Enemies2[j].invincibleRestTime > 0) {
			Enemies2[j].invincibleRestTime -= delta;
		}
		else {
			Enemies2[j].color = Enemy2.normalColor;
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies2[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					Enemies2[j].hp--;
					Enemies2[j].invincibleRestTime = Enemy2.invincibleTime;
					Enemies2[j].color = Enemy2.collisionColor;
					if (Enemies2[j].hp <= 0) {
						Enemy2.curNum--;
						Enemies2[j] = Enemies2[Enemy2.curNum];
					}

					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}
void ENEMIES_2::caunt() {
	if (Enemy2.curNum <= 0) { init(); }
}
void ENEMIES_2::draw() {
	for (int i = 0; i < Enemy2.curNum; i++) {
		imageColor(Enemies2[i].color);
		image(Enemy2.img, Enemies2[i].pos.x, Enemies2[i].pos.y, 0, 6);
	}
}
