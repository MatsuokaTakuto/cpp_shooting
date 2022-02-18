#include "GAME_CLEAR.h"
#include"CERECT.h"
#include"TITLE.h"
#include"TRANS.h"
#include"libOne.h"
#include"GAME.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {

}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::init() {
	game()->trans()->inTrigger();
}
void GAME_CLEAR::draw() {
	clear();
	fill(0, 255, 0);
	textSize(255);
	text("Game Clear", 400, 600);
	back();
	game()->trans()->draw();
}
void GAME_CLEAR::back() {
	GameClear.img = loadImage("assets\\StageBackImg.jpg");
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(GameClear.img, width / 2, height / 2, 0, 2);
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->title());
	}
}
