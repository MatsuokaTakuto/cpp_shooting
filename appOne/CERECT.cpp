#include "CERECT.h"
#include"GAME.h"
#include"STAGE.h"
#include"TRANS.h"
#include"CONTAINER.h"
CERECT::CERECT(class GAME* game) :
	SCENE(game) {

}
CERECT::~CERECT() {

}
void CERECT::init() {
	game()->trans()->inTrigger();
	Cerect.angle = 0;
	Cerect.siz = 0.1f;
}
void CERECT::draw() {
	clear();
	game()->fouran()->draw();
	setu();
	game()->trans()->draw();
}
void CERECT::setu() {
	rectMode(CORNER);
	textSize(200);
	fill(255,255,255);
	text("ルール説明", 10, 210);
	textSize(80);
	text("BOSSの", 980, 420);
	text("PLAYERの", 980, 640);
	text("がなくなる前に", 980, 530);
	text("をゼロにしよう！", 980, 750);
	fill(0, 255, 0);
	text("PLAYER", 60, 410);
	text("HP", 980 + 250, 420);
	fill(255, 0, 0);
	text("BOSS", 600, 410);
	text("HP", 980 + 330, 640);
	text("<SPACE>でスタート!",width/2-360,950);
	imageColor(255, 255, 255);
	Cerect.plimg = loadImage("assets\\players\\0\\pipo-airship01.png");
	image(Cerect.plimg, 160, 520, 0, 4);
	Cerect.emimg = loadImage("assets\\enemy_3.png");
	image(Cerect.emimg, 650, 520, 0, 4);
}
void CERECT::abe() {
	Cerect.img = loadImage("assets\\abe.jpg");
	rectMode(CENTER);
	Cerect.angle += Cerect.anglespeed;
	Cerect.siz += Cerect.sizspeed;
	image(Cerect.img, width / 2, height / 2, Cerect.angle, Cerect.siz);
}
void CERECT::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->trans()->outTrigger();
	}
	else if (isTrigger(KEY_SHIFT)) {
		game()->setCurScene(game()->gatya());
	}
	if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->stage());
	}
}
