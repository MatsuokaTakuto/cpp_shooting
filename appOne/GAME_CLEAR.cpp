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
	GameClear.img = loadImage("assets\\gameclear.png");
	GameClear.backimg = loadImage("assets\\clearback.jpg");
}
void GAME_CLEAR::draw() {
	clear();
	back();
	fill(0, 255, 0);
	textSize(250);
	text("Game Clear", 980-563, 600);
	game()->trans()->draw();
}
void GAME_CLEAR::back() {
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(GameClear.backimg, width / 2, height / 2);
	image(GameClear.img, width / 2, height / 2, 0, 1.2f);
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->title());
	}
}
