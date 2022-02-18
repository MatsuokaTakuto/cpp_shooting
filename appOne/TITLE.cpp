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
}
void TITLE::draw() {
	clear();
	back();
	fill(Title.textColor);
	textSize(Title.textSize);
	text(Title.str, Title.pos.x, Title.pos.y);
	textSize(75);
	fill(255, 255, 255);
	text("<SPACEでスタート>", width / 2-(4*75), height / 2 + 400);
	game()->trans()->draw();
}
void TITLE::back() {
	Title.img = loadImage("assets\\titleimg.jpg");
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(Title.img, width / 2, height / 2, 0, 7);
}
void TITLE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->cerect());
	}
}
