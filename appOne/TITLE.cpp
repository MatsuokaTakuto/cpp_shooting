#include"libOne.h"
#include"CERECT.h"
#include"GAME.h"
#include"TRANS.h"
#include"STAGE.h"
#include "TITLE.h"
#include"CONTAINER.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game) {
}
TITLE::~TITLE() {

}
void TITLE::create() {
	Title = game()->container()->title();
}
void TITLE::init() {
	game()->trans()->inTrigger();
	Title.img = loadImage("assets\\titleimg.jpg");
}
void TITLE::draw() {
	clear();
	back();
	textSize(75);
	fill(0, 0, 0);
	text("<SPACEでスタート>", width / 2-(4*75), height / 2 + 400);
	game()->trans()->draw();
}
void TITLE::back() {
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(Title.img, width / 2, height / 2, 0, 0.4f);
}
void TITLE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->cerect());
	}
}
