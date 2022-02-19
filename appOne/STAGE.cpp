#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"GAME_OVER.h"
#include"GAME_CLEAR.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"TRANS.h"
#include"TITLE.h"
#include "STAGE.h"
#include"CONTAINER.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {

}
void STAGE::create() {

}
void STAGE::init() {
	game()->playerBullets()->init();
	game()->enemyBullets()->init();
	game()->player()->init();
	game()->bossenemy()->init();
	game()->enemies2()->init();
	game()->enemies()->init();
	Stage.backImg = loadImage("assets\\StageBackImg.jpg");
	Stage.img = loadImage("assets\\StageBackImg.jpg");
	Stage.pos = VECTOR2(0, 0);

	game()->trans()->inTrigger();
}
void STAGE::update() {
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
	game()->player()->update();
	game()->bossenemy()->update();
	game()->enemies2()->update();
	game()->enemies()->update();
	caunt();
}
void STAGE::draw() {
	BackGround();
	game()->draw();
	game()->trans()->draw();
}
void STAGE::BackGround() {
	clear();
	rectMode(CORNER);
	imageColor(Stage.backColor);
	if(Stage.pos.x>=width){
		Stage.pos.x = -width;
	}
	image(Stage.backImg, Stage.pos.x, Stage.pos.y);
}
void STAGE::Back() {
	clear();
	rectMode(CORNER);
	imageColor(Stage.backColor);
	if(Stage.pos1.x>=width){
		Stage.pos1.x = -width;
	}
	image(Stage.img, Stage.pos1.x, Stage.pos1.y);

}
void STAGE::caunt() {

}
void STAGE::nextScene() {
	if (game()->bossenemy()->curNum()<=0) {
		game()->trans()->outTrigger();
	}
	if (game()->player()->hp() <= 0) {
		game()->setCurScene(game()->geme_over());
	}
	else if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->game_clear());
	}
}
