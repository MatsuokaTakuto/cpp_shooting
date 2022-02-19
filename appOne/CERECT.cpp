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
	Cerect.p2Img = loadImage("assets\\p2.png");
	Cerect.plimg = loadImage("assets\\players\\0\\pipo-airship01.png");
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
	text("<W,A,S,D>で移動", 1050, 200);
	text("<SPACE>で弾を発射", 1050, 310);
	text("BOSSの", 1050, 640);
	text("PLAYERの", 1050, 420);
	text("がなくなる前に", 1050, 530);
	text("をゼロにしよう！", 1050, 750);
	fill(0, 255, 0);
	text("PLAYER", 60, 410);
	text("HP", 1050 + 330, 420);
	fill(255, 0, 0);
	text("BOSS", 600, 410);
	text("HP", 1050 + 250, 640);
	text("<SPACE>でスタート!",width/2-360,950);
	imageColor(255, 255, 255);
	Cerect.emimg = loadImage("assets\\enemy_3.png");
	image(Cerect.emimg, 650, 520, 0, 4);
	if (game()->gatya()->gatyacaunt() == 1) {
		image(Cerect.p2Img, 160, 520, 0, 0.3f);
	}
	else {
		image(Cerect.plimg, 160, 520, 0, 4);

	}
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
