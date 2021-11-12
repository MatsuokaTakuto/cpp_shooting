#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMIES.h"
ENEMIES::ENEMIES(class GAME* game) :
	GAME_OBJECT(game) {
}
ENEMIES::~ENEMIES() {
	delete[] Enemies;
}
void ENEMIES::create(){
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMIES::init(){
	//3.14がラジアン値で180度、2倍にすることにより360度になる
	float divTheta = 3.14159265f * 2 / Enemy.totalNum;
	for (int i = 0; i < Enemy.totalNum; i++) {
		Enemies[i].ofstTheta = divTheta * i;
	}
}
void ENEMIES::update(){
	if (Enemy.centerPos.y < Enemy.targetPosY) {
		Enemy.centerPos.y += Enemy.fallSpeed * delta;
	}
	for (int i = 0; i < Enemy.totalNum; i++) {
		float theta = Enemy.refTheta + Enemies[i].ofstTheta;
		float px = Enemy.centerPos.x + cos(theta) * Enemy.majRadius;
		float py = Enemy.centerPos.y + sin(theta) * Enemy.minRadius;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}
	Enemy.refTheta += Enemy.thetaSpeed * delta;
}
void ENEMIES::draw(){
	for (int i = 0; i < Enemy.totalNum; i++) {
		image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y);
	}
}