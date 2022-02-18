#include"libOne.h"
#include"GAME.h"
#include"TITLE.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include "GAME_OVER.h"
#include"TRANS.h"
#include"ORUGA.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {

}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::init() {
	game()->trans()->inTrigger();
}
void GAME_OVER::update() {
	game()->playerBullets()->update();
	game()->enemyBullets()->update();

}
void GAME_OVER::draw() {
	clear();
	fill(255, 0, 0);
	textSize(255);
	text("Game Over", 400, 600);
	game()->oruga()->draw();
	game()->trans()->draw();
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag()) {
		game()->oruga()->set();
		game()->setCurScene(game()->title());
	}
}
